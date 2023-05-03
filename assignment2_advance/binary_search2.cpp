#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll> > arr;
void merge(int mid, int l, int r)
{
	vector<pair<ll,ll> > subArr1,subArr2;
	for (int i = l; i <= r; ++i)
	{
		if (i <= mid) subArr1.push_back(arr[i]);
		else subArr2.push_back(arr[i]);
	}
	int idx1 = 0, idx2 = 0, idx = l; 
	while(idx1 != subArr1.size() && idx2 != subArr2.size())
	{
		if (subArr1[idx1] > subArr2[idx2]) 
		{
			arr[idx] = subArr2[idx2];
			idx2++;
		}
		else 
		{
			arr[idx] = subArr1[idx1];
			idx1++;
		}
		idx++;
	}
	while (idx1 < subArr1.size()) 
	{
        arr[idx] = subArr1[idx1];
        idx1++;
        idx++;
    }
    while (idx2 < subArr2.size()) 
    {
        arr[idx] = subArr2[idx2];
        idx2++;
        idx++;
    }
}
void mergeSort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r)/2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(mid, l, r);
}
bool find(ll x)
{
	int l = 0, r = arr.size() - 1;
	while (l <= r) 
	{
		int mid = (l + r)/2;
		if (x > arr[mid].first) l = mid + 1;
		else if (x < arr[mid].first) r = mid - 1;
		else return true;
	}
	return false;
}
int first_x(ll x)
{
	int l = 0, r = arr.size();
	while (l < r) 
	{
		int mid = (l + r)/2;
		if (x > arr[mid].first) l = mid + 1;
		else r = mid;
	}
	return arr[l].second;
}
int last_x(ll x)
{
	int l = 0, r = arr.size();
	while(l < r)
	{
		int mid = (l + r)/2;
		if (arr[mid].first > x) r = mid;
		else l = mid + 1;
	}
	return arr[r-1].second;
}
int main()
{
	int n,q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		ll temp;
		cin >> temp;
		arr.push_back(make_pair(temp,i));
	}
	mergeSort(0, n-1);
	for (int i = 0; i < q; ++i)
	{
		string type;
		int x,y;
		cin >> type >> x >> y;
		if(!find(y)) cout<<"-1\n";
		else
		{
			if (x == 1) cout<<first_x(y) + 1<<'\n';
			if (x == 2) cout<<last_x(y) + 1<<'\n';
		}
	}
	return 0;
}