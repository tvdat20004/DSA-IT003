#include <bits/stdc++.h>
using namespace std;

int n, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    map<string, vector<string> > account;
    string name, pass;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> pass;
        account[name].push_back(pass);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> name;
        if (account.find(name) != account.end())
        {
            for (string p : account[name])
            {
                cout << p << " ";
            }
        }
        else
        {
            cout << "Chua Dang Ky!";
        }
        cout <<'\n';
    }
    return 0;
}