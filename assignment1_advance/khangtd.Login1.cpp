#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<string> userName, password;
bool check(string name,int &pos, string pass = "")
{
	for (int j = 0; j < userName.size(); ++j)
	{
		if (name == userName[j]) 
		{
			pos = j;
			return true;
		}
	}
	return false;
}
int main()
{
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		string name,pass;
		cin>>name>>pass;
		int pos = 0;
		if(!check(name,pos,pass))
		{
			userName.push_back(name);
			password.push_back(pass);
		}
		else password[pos] = pass; 
	}
	for (int i = 0; i < q; ++i)
	{
		string x;
		cin>>x;
		int pos(0);
		if(check(x,pos)) cout<<password[pos];
		else cout<<"Chua Dang Ky!";
		cout<<endl;
	}
	return 0;
}