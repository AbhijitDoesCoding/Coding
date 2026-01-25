#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mod 1000000007

ll binpow(ll b, ll p, ll m)
{
    ll a = 1;
    b %= m;
    while (p > 0)
    {
        if (p & 1)
            a = a * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return a;
}

void solve()
{
    ll n;
    cin >> n;

    ll exp = binpow(2, n, mod - 1);
    exp = (exp - 2 + (mod - 1)) % (mod - 1);

    ll ans = binpow(4, exp, mod);
    ans = ans * 6 % mod;

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
