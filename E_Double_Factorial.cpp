#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
ll binpow(ll b, ll p)
{
    ll ans = 1;
    // b %= mod1;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b;
        b = b * b;
    }
    return ans;
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

void solve()
{
    ll n;
    cin >> n;
    if(n & 1){
        cout << 0;
        return;
    }
    n >>
    ll ans = 0;
    ll powered;
    for (ll i = 1; (powered = binpow(5, i)) <= n; i++)
    {
        ans += n / powered;
        cout << powered << " " << ans << "\n";
    }
    cout << ans;
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