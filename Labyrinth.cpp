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
vector<string> arr; 
using state = pair<ll, ll>; 
vector<vector<ll>> vis, dist;
vector<vector<state>> par;

bool isValid(state next){
    ll x = next.first, y = next.second;

    if(x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != '#') return true;
    return false;
}

vector<ll> dx = {0, 0, 1, -1};
vector<ll> dy = {-1, 1, 0, 0};

vector<state> neighbours(state cur){
    vector<state> neigh;
    ll x = cur.first, y = cur.second;
    for(ll i = 0; i < 4; i++){
        if(isValid(make_pair(x+dx[i], y+dy[i]))){
            neigh.push_back({x+dx[i], y+dy[i]});
        }
    }
    return neigh;
}

void bfs(state st){
    queue<state> q;
    vis.assign(n, vector<ll> (m, 0));
    dist.assign(n, vector<ll> (m, inf));
    par.assign(n, vector<state> (m, {-1, -1}));
    
    dist[st.first][st.second] = 0;
    q.push(st);
    
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if(vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 1;
        
        auto neigh = neighbours(cur);
        for(auto x: neigh){
            if(!vis[x.first][x.second] && dist[x.first][x.second] > dist[cur.first][cur.second] + 1){
                dist[x.first][x.second] = dist[cur.first][cur.second] + 1;
                par[x.first][x.second] = {cur.first, cur.second};
                q.push(x);
            }
        }
    }
}

void solve() {
    cin >> n >> m; 
    state st, en; 
    arr.resize(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(arr[i][j] == 'A'){
                st = {i, j};
            }
            else if(arr[i][j] == 'B'){
                en = {i, j};
            }
        }
    }

    bfs(st);
    if(dist[en.first][en.second] == inf){
        cout << "NO\n"; return;
    }
    cout << "YES\n"; 
    cout << dist[en.first][en.second]; nline;
    state cur = en;
    string path; 
    while(cur != st){
        state x = par[cur.first][cur.second];
        if(x.first - cur.first == 0){
            if(x.second - cur.second == -1){
                path += 'R';
            }
            else{
                path += 'L';
            }
        }
        else if(x.first - cur.first == 1){
            path += 'U';
        }
        else{
            path += 'D';
        }
        cur = x;
    }
    reverse(path.begin(), path.end());
    cout << path << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}