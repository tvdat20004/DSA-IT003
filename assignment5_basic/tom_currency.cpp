#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	set<ll> denoms;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		denoms.insert(v[i]);
	}
	cout<<denoms.size()<<endl;
	for (ll denom : denoms)
	{
		cout<<denom<<' ';
	}
}