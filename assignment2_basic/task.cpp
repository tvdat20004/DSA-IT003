#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,p,q;
int main()
{
	cin>>n>>k>>p>>q;
	ll x = 2*(p-1) + q - k;
	ll y = 2*(p-1) + q + k;
	if (x > 0) 
	{
		if (x % 2) cout<<(x+1)/2<<' '<<1;
		else cout<<x/2<<' '<<2;
	}
	else if (y <= n) 
	{
		if (y % 2) cout<<(y+1)/2<<' '<<1;
		else cout<<y/2<<' '<<2;	
	}
	else cout<<-1;
	return 0;
}