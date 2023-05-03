#include <bits/stdc++.h>
#define ll long long
using namespace std;
// bool cmp_string(string a,string b)
// {
//  if (a.length() != b.length()) return a.length() < b.length();
//  else return a < b;
// }
bool isLessThan(string a, string b){
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] > b[i]) return false;
        else if (a[i] < b[i]) return true;
    }
    return false;
}
bool isEqual(string a, string b){
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]) return false;
    }
    return true;
}
bool cmp_pair(pair<string,ll> a, pair<string,ll> b)
{
    if (a.second != b.second) return a.second > b.second;
    else return isLessThan(a.first, b.first);
}
void quickSort_item_code(vector<string> &arr, ll left, ll right) {
    ll i = left, j = right;
    string pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (isLessThan(arr[i], pivot))
            i++;

        while (isLessThan(pivot, arr[j]))
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort_item_code(arr, left, j);
    if (i < right)
        quickSort_item_code(arr, i, right);
}
void quickSort_f(vector<pair<string, ll>> &arr, ll left, ll right) {
    ll i = left, j = right;
    pair<string, ll> pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (cmp_pair(arr[i], pivot))
            i++;

        while (cmp_pair(pivot, arr[j]))
            j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort_f(arr, left, j);

    if (i < right)
        quickSort_f(arr, i, right);
}
int main()
{
    ll n;
    cin>>n;
    if (!n) return 0;
    vector<string> item_code(n + 1);
    string temp;
    for (ll i = 1; i <= n; ++i)
    {
        cin>>item_code[i];
    }
    quickSort_item_code(item_code,1,n);
    vector<pair<string,ll> > f;
    f.push_back({item_code[1],1});
    for (ll i = 2; i <= n; ++i)
    {
        if (!isEqual(item_code[i], item_code[i - 1])) f.push_back({item_code[i],1});
        else f[f.size() - 1].second ++; 
    }
    quickSort_f(f,0, f.size() - 1);
    for(auto x : f)
    {
        cout<<x.first<<' '<<x.second<<'\n';
    }
    return 0;
}