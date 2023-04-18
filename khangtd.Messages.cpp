#include <bits/stdc++.h>
using namespace std;
int main()
{
	string sb,se;
	cin >> sb >> se;
	int n_loop = min(sb.length(), se.length());
	string loop = "";
	while (n_loop > 0 )
	{
		if (sb.substr(sb.length() - n_loop, n_loop) == se.substr(0,n_loop)) 
		{
			loop = se.substr(0,n_loop);
			sb.erase(sb.length() - n_loop);
			se.erase(0,n_loop);
			break;	
		}
		n_loop--;
	}
	cout<<se.length() + sb.length() + n_loop<<endl;
	cout<<sb + loop + se;
	return 0;
}