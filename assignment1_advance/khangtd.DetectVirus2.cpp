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

void KMP(string S, string T) {
    int n = S.length();
    int m = T.length();
    vector<int> p = computePrefix(T);
    vector<int> ans;
    int q = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        while (q > 0 && T[q] != S[i]) {
            q = p[q-1];
        }
        if (T[q] == S[i]) {
            q++;
        }
        if (q == m) {
            found = true;
            ans.push_back(i-m+2);
            q = p[q-1];
        }
    }
    if (!found) {
        cout << "NO\n";
    }
    else 
    {
    	cout<<"YES\n";
    	for(int x : ans)
    		cout<<x<<" ";
    }
}

int main() {
    string S, T;
    cin >> S >> T;
    KMP(S, T);
    return 0;
}