#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	int x;
	cin>>a>>x;
	string ans = "";
	while(a > 0)
	{
		ans = to_string(a % x) + ans;
		a /= x;
	}
	cout<<ans;
	return 0;
}