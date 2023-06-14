#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	ll s,n,temp;
	priority_queue<ll,vector<ll>, decltype(&cmp) > a(cmp);
	cin>>n>>s;
	for (ll i = 0; i < n; ++i)
	{
		cin>>temp;
		a.push(temp);
	}
	ll ans = 0;
	while (a.size() != 1)
	{
		ll a1 = a.top();
		a.pop();
		ll a2 = a.top();
		a.pop();
		a.push(a1 + a2);
		ans += a1 + a2;
		// cout<<a1+a2<<endl;
	}
	cout<<ans;
}