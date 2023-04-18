#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sizeOfArr,x;
	cin >> sizeOfArr;
	int arr[sizeOfArr];
	for (int i = 0; i < sizeOfArr; ++i)
	{
		cin >> arr[i];
	}
	cin >> x;
	bool appear = 0;
	for (int i = 0; i < sizeOfArr; ++i)
	{
		if (arr[i] == x) 
		{
			cout<<i + 1<<" ";
			appear = 1;
		}
	}
	if (!appear) cout<<"NO";
	return 0;
}