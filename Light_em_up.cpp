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
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll binpow(ll b,ll p){ll a=1;for(b%=mod;p;p>>=1,b=b*b%mod) if(p&1)a=a*b%mod;return a;}
ll modinv(ll a){return binpow(a,mod-2);}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;
    if (k == 0)
    {
        for (ll x : a)
        {
            if (x == 0)
            {
                cout << -1 << "\n";
                return;
            }
        }
        cout << 0 << "\n";
        return;
    }

    vector<ll> diff(n + 1, 0);
    ll flips = 0, cur = 0;

    for (ll i = 0; i < n; i++)
    {
        cur += diff[i];
        cur %= 2;

        ll val = a[i];
        if (cur)
            val = 1 - val;

        if (val == 0)
        {
            if (i + k > n)
            {
                cout << -1 << "\n";
                return;
            }
            flips++;
            cur++;
            diff[i + k]--;
        }
    }

    cout << flips << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}