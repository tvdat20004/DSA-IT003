#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
const ll M = 1e5 + 5;
ll p[M + 10];
ll power(ll x,ll y)
{
    if (!y) return 1;
    if (y == 1) return x;
    ll value = power(x,y/2);
    value = (value * value) % MOD;
    if (y%2) value = (value * x) % MOD;
    return value;
}
ll C(ll x,ll k)
{
    if (x < k) return 0;
    ll a = p[x];
    ll b = (p[k] * p[x-k]) % MOD;
    b = power(b,MOD - 2);
    return (a * b) % MOD;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n+1);
    vector<ll>q;
    p[0] = 1;
    for (ll i = 1;i <= M; i++) 
        p[i] = (p[i - 1] * i) % MOD;
    for (ll i = 1;i <= n; i++)
        cin>>a[i];
    for (ll i = 1;i <= n; i++)
        q.push_back(a[i]);
    ll ans = 0;
    sort(q.begin(),q.end());
    ll cnt = 0;
    for (ll x : q)
    {
        cnt++;
        ll value_x = (n - cnt);
        ans = (ans - C(value_x,k - 1) * x+3 * MOD) % MOD;
        ll value_y = cnt - 1;
        ans = (ans + C(value_y,k-1) * x) % MOD;
    }
    cout<<ans;
    return 0;
}