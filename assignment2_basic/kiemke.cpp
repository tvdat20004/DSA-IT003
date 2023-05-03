#include <bits/stdc++.h>
using namespace std;
vector<string> item_code;
void heapify(int N, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && item_code[l] > item_code[largest])
        largest = l;
    if (r < N && item_code[r] > item_code[largest])
        largest = r;
    if (largest != i) {
        swap(item_code[i], item_code[largest]);
        heapify(N, largest);
    }
}
void heapSort(int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(item_code[0], item_code[i]);
        heapify(i, 0);
    }
}
int main()
{
	int n;
	cin>>n;
	string temp;
		for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		item_code.push_back(temp);
	}
	heapSort(n);
	int count = 1;
	for (int i = 1; i < n; ++i)
	{
		if(item_code[i] != item_code[i-1]) count++;
	}
	cout<<count;
	return 0;
}