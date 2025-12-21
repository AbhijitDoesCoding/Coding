#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define yes cout << "YES\n";
#define no cout << "NO\n";
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
    ll n, k, s;
    cin >> n >> k >> s;
    ll checksum = k * (n - 1);
    if (s > checksum || k > s)
    {
        no;
        return;
    }
    yes;
    s -= k;
    ll curr = 1;
    loop(i, 0, k)
    {
        ll move = min(s, n - 2);
        s -= move;
        move++;
        curr = (i % 2 == 0 ? curr + move : curr - move);

        cout << curr << " ";
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