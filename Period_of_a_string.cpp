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
#define loop(i, l, h) for (ll i = l; i < h; i++)
#define rev(i, l, h) for (ll i = h - 1; i >= l; i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }
ll binpow(ll b, ll p)
{
    ll a = 1;
    for (b %= mod; p; p >>= 1, b = b * b % mod)
        if (p & 1)
            a = a * b % mod;
    return a;
}
ll modinv(ll a) { return binpow(a, mod - 2); }

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll, ll> pi;
vector<ll> calculateZ(string s)
{
    ll n = s.length();
    vector<ll> Z(n);
    ll L = 0, R = 0;

    for (ll i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            ll k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && s[R - L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

void solve()
{

    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> z = calculateZ(s);
    ll valueTo = 0;
    ll index = -1;
    for (ll i = 0; i < n; i++)
    {
        if (z[i] != 0)
        {
            valueTo = z[i];
            index = i;
            break;
        }
    }
    if (valueTo == 0)
        return;
    valueTo++;
    ll k = 2;
    for (ll i = index + index; i <= valueTo; i += index)
    {
        cout << i << " " << k++ << "\n";
    }
    nline;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll testCases = 1;
    ll t = 1;
    cin >> t;
    while (t--){
        cout << "Test case #" << testCases++ << "\n";
        solve();
    }
    return 0;
}