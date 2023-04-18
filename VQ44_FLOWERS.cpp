#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll> color;
    ll n,k;
    cin >> n >> k;
    for (ll i = 0; i < n; ++i)
    {
        ll temp;
        cin>>temp;
        color.push_back(temp);
    }
    set<ll> non_duplicate;
    for(int i=0;i<=n-1;i++)
    {
        non_duplicate.insert(color[i]);
    }
    sort(color.begin(),color.end());
    ll count = 1;
    if (k <= non_duplicate.size())
    {
        for (auto i = non_duplicate.begin(); i != non_duplicate.end(); ++i)
        {
            if (count <= k) cout<<*i<<' ';
            count ++;
        }
    }
    else
    {
        for(auto x : non_duplicate)
        {
            cout<<x<<' ';
        }
        k -= non_duplicate.size();
        int index = n-1;
        while (k > 0)
        {
            if (color[index] == color[index-1])
            {
                cout<<color[index]<<" ";
                k--;
            }
            index--;
        }
    }
    return 0;
}