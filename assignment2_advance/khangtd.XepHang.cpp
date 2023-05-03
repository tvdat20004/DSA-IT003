#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    vector<bool> mssv(n,0);
    vector<int> request;
    int temp;
    for (int i = 0; i < m; ++i)
    {
        cin>>temp;
        request.push_back(temp);
    }
    for (int i = m - 1; i >= 0; --i)
    {
        if(mssv[request[i]] == 0)
        {
            cout<<request[i]<<' ';
            mssv[request[i]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mssv[i] == 0) cout<<i<<' ';
    }
    return 0;
}