#include<bits/stdc++.h>
using namespace std;

vector<int> computePrefix(string T) {
    int m = T.length();
    vector<int> p(m);
    p[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && T[k] != T[i]) {
            k = p[k-1];
        }
        if (T[k] == T[i]) {
            k++;
        }
        p[i] = k;
    }
    return p;
}

bool KMP(const vector<char>& S, const string& T) {
    int n = S.size();
    int m = T.length();
    vector<int> p = computePrefix(T);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && T[q] != S[i]) {
            q = p[q-1];
        }
        if (T[q] == S[i]) {
            q++;
        }
        if (q == m) {
            return true;
        }
    }
    return false;
}

bool findVirusInMatrix(const vector<vector<char>>& data, int m, int n, const string& virus) {
    for (int i = 0; i < m; ++i) {
        if (KMP(data[i], virus)) {
            return true;
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<char> col(m);
        for (int j = 0; j < m; ++j) {
            col[j] = data[j][i];
        }
        if (KMP(col, virus)) {
            return true;
        }
    }
    return false;
}

int main() {
    int m, n, q;
    cin >> m >> n >> q;
    vector<vector<char>> data(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> data[i][j];
        }
    }
    string virus;
    while (q--) {
        cin >> virus;
        cout << findVirusInMatrix(data, m, n, virus);
    }
    return 0;
}