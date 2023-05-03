#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    vector<int> mssv(m+n+1);
    vector<int> pos(n+1);
    for (int i = 1; i <= n; ++i)
    {
        mssv[i + m] = i;
        pos[i] = i + m;
    }
    int request;
    for (int i = m; i >= 1; --i)
    {
        cin>>request;
        mssv[i] = request;
        mssv[pos[request]] = 0;
        pos[request] = i;
        for(int j = m + n; j >= 1; j--)
        {
            if(mssv[j] != 0)
            {
                cout<<mssv[j]<<' ';
                break;
            }
        }
    }
    return 0;
}