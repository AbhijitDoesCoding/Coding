#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i, l, h) for (int i = l; i < h; i++)
#define rev(i, l, h) for (int i = h - 1; i >= l; i--)
ll binpow(ll b, ll p, ll mod1)
{
    ll ans = 1;
    b %= mod1;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b % mod1;
        b = b * b % mod1;
    }
    return ans;
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

void sieve(vi &a, ll n, vi &b)
{
    for (ll i = 2; i <= n; i++)
    {

        if (a[i] == 1)
        {
            b.pb(i);
            for (ll j = i * i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    vi a(sqrt(r) + 1, 1);
    vi b;
    sieve(a, sqrt(r), b);

    vi c(r - l + 1, 1);
    vi d;
    loop(i, 0, b.size())
    {

        ll mul = ((l + b[i] - 1) / b[i]) * b[i];
        for (ll j = mul; j <= r; j += b[i])
        {
            c[j - l] = 0;
        }
        if (mul == b[i])
            c[mul - l] = 1;
    }

    loop(i, 0, c.size())
    {
        if (c[i] == 1)
        {
            if (i + l != 1)
                d.pb(i + l);
        }
    }
    cout << d.size() << "\n";
    loop(i, 0, d.size())
    {
        cout << d[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;

    while (t--)
    {
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}