#include<bits/stdc++.h>
using namespace std; typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define loop(i,l,h) for(ll i=l;i<h;i++)
#define rev(i,l,h) for(ll i=h-1;i>=l;i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll binpow(ll b,ll p){ll a=1;for(b%=mod;p;p>>=1,b=b*b%mod) if(p&1)a=a*b%mod;return a;}
ll modinv(ll a){return binpow(a,mod-2);}
ll ncr(ll n, ll r)
{ 
    ll num = 1, den = 1;
    for (ll i = 1; i <= r; i++)
    {
        num = (num * (n - i + 1)) % mod;
        den = (den * i) % mod;
    }
    return (num * modinv(den)) % mod;
}
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

void solve()
{
    string s, t;
    cin >> s >> t;

    ll a = 0, b = 0, q = 0;

    for (char c : s)
        a += (c == '+' ? 1 : -1);
    for (char c : t)
    {
        if (c == '+')
            b++;
        else if (c == '-')
            b--;
        else
            q++;
    }

    ll diff = a - b;

    if ((diff + q) % 2 != 0)
    {
        cout << "0.000000000000";
        return;
    }

    ll p = (diff + q) / 2;

    if (p < 0 || p > q)
    {
        cout << "0.000000000000";
        return;
    }

    double ans = (double)ncr(q, p) / binpow(2, q);
    cout << fixed << setprecision(12) << ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}