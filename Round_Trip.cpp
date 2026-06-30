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
ll n, m; 
vector<ll> col;
vector<vector<ll>> edges; 

bool isCycle; 

void dfs(ll cur, ll parent){
    if(isCycle) return;
    col[cur] = 2;

    for(auto x: edges[cur]){
        if(x == parent) continue; 

        if(col[x] == 1){
            dfs(x, cur);
        }
        else if(col[x] == 2){
            isCycle = true;
            return;
        }
    }

    col[cur] = 3;
}
void solve() {
    cin >> n >> m; 
    col.assign(n+1, 1);
    isCycle = false;
    edges.resize(n+1, vector<ll> ());
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y; 
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(ll i = 1; i < n+1; i++){
        if(col[i] == 1){
            dfs(i, 0);
        }
    }

    if(isCycle) cout << "YES";
    else cout << "NO";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}