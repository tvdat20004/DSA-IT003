#include <bits/stdc++.h>
using namespace std;
vector<long long> arr;
bool find(long long x)
{
	int l = 0, r = arr.size() - 1;
	while (l <= r) 
	{
		int mid = (l + r)/2;
		if (x > arr[mid] ) l = mid + 1;
		else if (x < arr[mid]) r = mid - 1;
		else return true;
	}
	return false;
}
int main()
{
	int size_of_arr,numOfquery;
	cin >> size_of_arr >> numOfquery;
	for (int i = 0; i < size_of_arr; ++i)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp); 
	}
	sort(arr.begin(),arr.end());
	for (int i = 0; i < numOfquery; ++i)
	{
		long long x;
		cin >> x;
		if (find(x)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}