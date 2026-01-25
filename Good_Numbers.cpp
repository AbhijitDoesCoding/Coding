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

void solve()
{
    ll n, k, q;
    cin >> n >> k >> q;
    vi a(1000001, 0);
    loop(i, 0, n)
    {
        ll l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    loop(i, 1, 1000001)
    {
        a[i] += a[i - 1];
    }
    vi prefix_sum(1000001, 0);
    prefix_sum[0] = a[0];
    loop(i, 1, 1000001)
    {
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }
    while (q--)
    {
        ll x;
        cin >> x;
        if (x < 0 || x >= 1000001)
        {
            cout << 0 << "\n";
            continue;
        }
        if (prefix_sum[x] >= k)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
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