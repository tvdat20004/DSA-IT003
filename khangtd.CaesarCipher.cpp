#include <bits/stdc++.h>
using namespace std;
char letter(int x)
{
	return (char)(x + 'A');
}
int main()
{
	long long k;
	cin>>k;
	string plaintext;
	cin.ignore(256, '\n');
	getline(cin,plaintext);
	for (int i = 0; i < plaintext.length(); ++i)
	{
		if (plaintext[i] >= 'A' && plaintext[i] <= 'Z' )
		plaintext[i] = letter((int)(plaintext[i] - 'A' + k) % 26);
		cout<<plaintext[i];
	}
	return 0;
}