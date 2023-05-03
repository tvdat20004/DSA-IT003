#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<ll> arr;
void heapify(int N, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(N, largest);
    }
}
void heapSort(int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}
int main()
{
	cin>>n;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	heapSort(n);
	if(arr[0] != 0) 
	{
		cout<<0;
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] - 1 != arr[i-1])
		{
			cout<<arr[i-1] + 1;
			return 0;
		}
	}
	cout<<arr[n-1] + 1;
	return 0;
}