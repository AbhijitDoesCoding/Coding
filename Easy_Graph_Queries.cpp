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
vector<ll> comp;
vector<vector<ll>> edges;
ll c;
void dfs(ll start){
    if(!visited[start]){
        visited[start] = 1;
        comp[start] = c;
        for(auto x: edges[start]){
            dfs(x);
        }
    }
}

void solve() {
    ll n, m, q; 
    cin >> n >> m >> q;
    visited.assign(n+1, 0);
    comp.assign(n+1, 0); 
    edges.resize(n+1);
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y; 
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(ll i = 1; i < n+1; i++){
        if(!visited[i]){c++;}
        dfs(i);
    }
    vector<ll> comp_sizes(n+1, 0);
    for(ll i = 0; i < n+1; i++){
        comp_sizes[comp[i]]++;
    }
    for(ll i = 0; i < q; i++){
        ll u; cin >> u;
        ll x, y;
        
        if (u == 2) {
            cin >> x >> y; 
            if(comp[x] == comp[y]){
            cout << "YES\n";
            }
            else{
            cout << "NO\n";
            }
        } else {
            cin >> x;
            cout << comp_sizes[comp[x]] << "\n";
        }
        
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}