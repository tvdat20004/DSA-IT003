// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// vector<ll> _side;

// ll count_validSide(ll side)
// {
// 	ll l = 0, r = _side.size() - 1;
// 	ll mid;
// 	if (side * 2 > _side.back()) return _side.size();
// 	while (l <= r)
// 	{
// 		mid = (l + r) / 2;
// 		// cout<<mid<<endl;
// 		if (2 * side == _side[mid]) return mid;
// 		if (2 * side < _side[mid]) r = mid-1;
// 		else l = mid+1;
// 	}
// 	return r + 1;	
// }
// int main()
// {
// 	ll n,temp;
// 	cin>>n;
// 	map<ll,ll> side;
// 	for (ll i = 0; i < n; ++i)
// 	{
// 		cin>>temp;
// 		side[temp]++;
// 		_side.push_back(temp);
// 	}
// 	sort(_side.begin(), _side.end());
// 	ll count_isoTriangle = 0, count_equilTriangle = 0;
// 	for (auto s : side)
// 	{
// 		if (s.second >= 2) 
// 		{
// 			// cout<<s.first<<' '<<count_validSide(s.first)<<endl;
// 			count_isoTriangle += (count_validSide(s.first) - 2) * s.second * (s.second - 1) / 2;
// 		}
// 		if (s.second >= 3) count_equilTriangle += s.second * (s.second-1) * (s.second-2) / 6;
// 	}
// 	cout<<count_isoTriangle - 2*count_equilTriangle;
// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[500005];

map<ll, ll> cnt;
vector<ll> edge;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!cnt[a[i]])
            edge.push_back(a[i]);
        cnt[a[i]]++;
    }
    sort(edge.begin(), edge.end());
    ll ans = 0, dem = 0;
    int l1 = 0;
    for (int l = 0; l < edge.size(); l++)
    {
        while (l1 < edge.size() && edge[l1] < edge[l] * 2)
        {
            dem += cnt[edge[l1]];
            l1++;
        }
        ans += cnt[edge[l]] * (cnt[edge[l]] - 1) / 2 * (dem - cnt[edge[l]]);
        ans += cnt[edge[l]] * (cnt[edge[l]] - 1) * (cnt[edge[l]] - 2) / 6;
    }
    cout << ans;
}
