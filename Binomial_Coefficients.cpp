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
ll fact[1000100];
ll invfact[1000100];
void precompute_for_faster()
{ // O(n) + O(log(mod)) + O(n) ~ O(n + log(mod))
    fact[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[1000000] = modinv(fact[1000000]);
    for (ll i = 1000000; i >= 1; i--)
    {
        invfact[i - 1] = (invfact[i] * i) % mod;
    }
}

ll ncr_fact_faster(ll n, ll r)
{ // O(1)
    ll num = fact[n];
    ll den = (invfact[n - r] * invfact[r]) % mod;
    return (num * den) % mod; // den is already inverted
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

void solve(){
    ll n, r; cin >> n >> r;
    cout << ncr_fact_faster(n, r); nline
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precompute_for_faster();
    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}