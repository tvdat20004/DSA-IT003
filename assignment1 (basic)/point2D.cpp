#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp( pair<ll,ll> A, pair<ll,ll> B)
{
	if (A.first != B.first) return (A.first < B.first);
	else return (A.second > B.second);
}
int main()
{
	ll n;
	cin >>n;
	vector<pair<ll,ll> > point;
	for (ll i = 0; i < n; ++i)
	{
		int temp_x,temp_y;
		cin >> temp_x >> temp_y;
		point.push_back(make_pair(temp_x,temp_y));
	}
	sort(point.begin(),point.end(), cmp);
	for (ll i = 0; i < n; ++i)
	{
		cout<<point[i].first<<' '<<point[i].second<<'\n';
	}
	return 0;
}