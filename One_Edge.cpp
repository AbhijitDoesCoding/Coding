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

vector<ll> visited;
ll k; 
ll c; 
vector<vector<ll>> edges; 
vector<ll> st; 

void dfs(ll i){
    if(!visited[i]){
        visited[i] = 1; 
        st[c]++;
        for(ll j = 0; j < edges[i].size(); j++){
            dfs(edges[i][j]);
        }
    }
}

void solve() {
    ll n, m; cin >> n >> m; 
    edges.resize(n+1);
    visited.assign(n+1, 0);
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            st.pb(0);
            dfs(i);
            c++;
        }
    }

    ll ans = 0, sum = 0;
    for(ll x : st){
        ans += x * sum;
        sum += x;
    }

    cout << ans; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}