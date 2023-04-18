#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,k;
	cin>>n>>k;
	int mssv_trc[n];
	for (ll i = 0; i < n; ++i)
	{
		cin>>mssv_trc[i];
	}
	int mssv_sau[n];
	for (ll i = 0; i < n; ++i)
	{
		mssv_sau[(i + k) % n] = mssv_trc[i]; 
	}
	for (ll i = 0; i < n; ++i)
	{
		cout<<mssv_sau[i]<<" ";
	}
	return 0;
}