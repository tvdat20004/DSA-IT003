#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point3D
{
	ll x,y,z;
};
ll n;
vector<point3D> point;
bool cmp(point3D a, point3D b)
{
	if (a.x != b.x) return a.x < b.x;
	else if (a.y != b.y) return a.y > b.y;
	else return a.z < b.z;
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
	ll temp_x,temp_y,temp_z;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp_x>>temp_y>>temp_z;
		point.push_back({temp_x,temp_y,temp_z});
	}
	heapSort(n);
	for(auto i : point)
	{
		cout<<i.x<<" "<< i.y<<' '<<i.z<<'\n';
	}
	return 0;
}