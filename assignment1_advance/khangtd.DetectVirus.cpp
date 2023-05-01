#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin >>s>>t;
	int x = s.find(t);
	if (x >= 0) cout<<"YES\n";
	else 
	{
		cout<<"NO\n";
		return 0;
	}
	vector <int> pos;
	for (int i = 0; i <= s.length() - t.length(); ++i)
	{
		if (t == s.substr(i,t.length()))
		{
			pos.push_back(i + 1);
		}
	}
	for( int x : pos)
	{
		cout<<x<<' ';
	}
	return 0;
}