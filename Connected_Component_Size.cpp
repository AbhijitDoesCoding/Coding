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
vector<vector<ll>> graph;
ll c; 
unordered_map<ll, ll> comp_size;
vector<vector<ll>> comps; 
using state = pair<ll, ll>;
vector<vector<ll>> maps; 

vector<ll> dx = {0, 0, -1, 1};
vector<ll> dy = {-1, 1, 0, 0};

bool isValid(state cur){
    auto [x, y] = cur;
    if(x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != 1) return true;
    return false;
}

vector<state> neighbours(state cur){
    vector<state> u; 
    ll x = cur.first, y = cur.second;
    for(ll i = 0; i < 4; i++){
        if(isValid({x + dx[i], y + dy[i]})){
            u.push_back({x + dx[i], y + dy[i]});
        }
    }
    return u;
}

void dfs(state cur){
    if(!graph[cur.first][cur.second]){
        graph[cur.first][cur.second] = 1;
        comp_size[c]++;
        comps[cur.first][cur.second] = c;
        
        auto neigh = neighbours(cur);

        for(auto [x, y] : neigh){
            dfs({x, y});
        }
    }
}

void solve() {
    cin >> n >> m; 
    comp_size.clear();
    graph.assign(n, vector<ll> (m, 0));
    maps.assign(n, vector<ll> (m, 0));
    comps.assign(n, vector<ll> (m, -1));
    c = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> maps[i][j];
        }
    }
    graph = maps;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!graph[i][j]){
                c++; 
                dfs({i, j});
            }
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(!maps[i][j]){
                if(comp_size[comps[i][j]] == 1){
                    maps[i][j] = 0;
                }
                else{
                    maps[i][j] = comp_size[comps[i][j]];
                }
            }
            cout << maps[i][j] << " ";
        }
        nline;
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}