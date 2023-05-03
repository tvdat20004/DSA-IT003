/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
sort
stable_sort
partial_sort
partial_sort_copy
sort_heap
###End banned keyword*/

//###INSERT CODE HERE -
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point2D
{
	ll x,y;
};
ll n;
vector<point2D> point;
bool cmp(point2D a, point2D b)
{
	if (a.x != b.x) return a.x < b.x;
	else return a.y > b.y;
}
void heapify(int N, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && !cmp(point[l], point[largest]))
        largest = l;
    if (r < N && !cmp(point[r], point[largest]))
        largest = r;
    if (largest != i) {
        swap(point[i], point[largest]);
        heapify(N, largest);
    }
}
void heapSort(int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(point[0], point[i]);
        heapify(i, 0);
    }
}
int main()
{
	cin >>n;
	ll temp_x,temp_y;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp_x>>temp_y;
		point.push_back({temp_x,temp_y});
	}
	heapSort(n);
	for(auto i : point)
	{
		cout<<i.x<<" "<< i.y<<'\n';
	}
	return 0;
}