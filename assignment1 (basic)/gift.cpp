#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> arr;
    for (int i = 0; i < n; ++i)
    {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    ll maxSum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (x > arr[i])
        {
            ll rest = x - arr[i];
            if (rest >= arr[n - 1])
            {
                ll sum;
                for (int j = i + 1; j < n; ++j)
                {
                    if (rest >= arr[j])
                    {
                        sum = arr[i] + arr[j];
                        break;
                    }
                }
                maxSum = max(maxSum,sum);
            }
        }
    }
    cout<<maxSum;
    return 0;
}