#include<bits/stdc++.h>
using namespace std;
string dec_to_bin(int dec)
{
	string bin = "";
	if (dec < 2) return bin + to_string(dec);
	else 
	{
		bin += to_string(dec % 2) + dec_to_bin(dec / 2);
	}
	//reverse(bin.begin(), bin.end());
	return bin;
}
int main()
{
	int dec;
	cin>>dec;
	string bin = dec_to_bin(dec);
	reverse(bin.begin(), bin.end());
	cout<<bin;
}