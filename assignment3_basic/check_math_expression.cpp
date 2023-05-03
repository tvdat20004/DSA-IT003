#include<bits/stdc++.h>
using namespace std;
int main()
{
	string latex;
	stack <char> bracket;
	cin>>latex;
	for (int i = 0; i < latex.length(); ++i)
	{
		if (latex[i] == '{' || latex[i] == '[' || latex[i] == '(') bracket.push(latex[i]);
		else
		{
			if (latex[i] == '}') 
			{
				if (!bracket.empty() && bracket.top() == '{') bracket.pop();
				else 
				{
					cout<<0;
					return 0;
				}
			}
			if (latex[i] == ')') 
			{
				if (!bracket.empty() && bracket.top() == '(') bracket.pop();
				else 
				{
					cout<<0;
					return 0;
				}
			}
			if (latex[i] == '[') 
			{
				if (!bracket.empty() && bracket.top() == ']') bracket.pop();
				else 
				{
					cout<<0;
					return 0;
				}
			}
		}
	}
	if (bracket.empty()) cout<<1;
	else cout<<0;
	return 0;
}