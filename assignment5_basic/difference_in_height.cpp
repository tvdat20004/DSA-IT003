#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ll ans = 0, coef = n - 1;
	sort(a.begin(),a.end(), greater<ll>());
	for (int i = 0; i < n; ++i)
	{
		ans += coef * a[i];
		coef -= 2;
	}
	cout<<ans;
	return 0;
}