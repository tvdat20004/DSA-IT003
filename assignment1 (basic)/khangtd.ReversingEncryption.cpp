#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0) reverse(s.begin(),s.begin() + i);
	}
	cout<<s;
	return 0;
}