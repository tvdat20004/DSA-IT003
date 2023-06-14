#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	stack<char> leter;
	for (int i = 0; i < s.length(); ++i)
	{
		if (leter.empty()) 
		{
			leter.push(s[i]);
			continue;
		}
		if (leter.top() == s[i]) leter.pop();
		else leter.push(s[i]);
	}
	cout<<leter.size();
}