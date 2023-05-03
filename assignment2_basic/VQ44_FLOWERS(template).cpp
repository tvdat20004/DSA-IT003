#include <bits/stdc++.h>
#define ll long long
using namespace std;
void heapify(int N, int i,vector<ll> &color)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && color[l] > color[largest])
        largest = l;
    if (r < N && color[r] > color[largest])
        largest = r;
    if (largest != i) {
        swap(color[i], color[largest]);
        heapify(N, largest,color);
    }
}
void heapSort(int N,vector<ll> &color)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i,color);
    for (int i = N - 1; i > 0; i--) {
        swap(color[0], color[i]);
        heapify(i, 0,color);
    }
}
int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> color;
    ll temp;
    for (ll i = 0; i < n; ++i)
    {
        cin>>temp;
        color.push_back(temp);
    }
    heapSort(n,color); 
    vector<ll> non_duplicate;
    non_duplicate.push_back(color[0]);
    for(int i=1;i < n;i++)
    {
        if (color[i] != color[i - 1])
        {
            non_duplicate.push_back(color[i]);
        }
    }
    ll count = 1;
    if (k <= non_duplicate.size())
    {
        for (int i = 0; i < k; i++)
        {
            cout<<non_duplicate[i]<<' ';
        }
    }
    else
    {
        for(auto x : non_duplicate)
        {
            cout<<x<<' ';
        }
        k -= non_duplicate.size();
        int index = n-1;
        while (k > 0)
        {
            if (color[index] == color[index-1])
            {
                cout<<color[index]<<" ";
                k--;
            }
            index--;
        }
    }
    return 0;
}