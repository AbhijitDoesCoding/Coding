#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

ll binpow(ll b, ll p) {
    ll a = 1;
    for (b %= mod; p; p >>= 1, b = b * b % mod)
        if (p & 1) a = a * b % mod;
    return a;
}

ll modinv(ll a) {
    return binpow(a, mod - 2);
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
vector<vector<ll>> a;
ll n; 
vector<vector<ll>> dp;
ll rec(ll i, ll prev){
    if(i == n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];
    ll ofa = 0, ofb = 0, ofc = 0;
    
    if(!(prev == 1)){
        ofa = a[i][0] + rec(i+1, 1);
    }
    if(!(prev == 2)){
        ofb = a[i][1] + rec(i+1, 2);
    }
    if(!(prev == 3)){
        ofc = a[i][2] + rec(i+1, 3);
    }
    ll u = max(ofa, max(ofb, ofc));
    dp[i][prev] = u;
    return u;
}

void solve() {
    cin >> n; 
    a.assign(n, vector<ll> (3, 0));
    for(ll i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    dp.assign(n, vector<ll> (4, -1));

    cout << rec(0, 0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}