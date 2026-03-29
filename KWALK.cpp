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

using state = pair<ll, ll>;
vector<vector<ll>> dist;
ll fx, fy;
ll n;
vector<ll> dx = {-2, -2, -1, 1, 2, 2, -1, 1};
vector<ll> dy = {-1, 1, -2, -2, -1, 1, 2, 2};

void bfs(state st){
    queue<state> q;
    q.push(st);
    dist[st.first][st.second] = 0;

    while(!q.empty()){
        auto cur = q.front(); 
        q.pop();

        ll x = cur.first, y = cur.second;

        if(x == fx && y == fy) return;

        for(int i = 0; i < 8; i++){
            ll nx = x + dx[i];
            ll ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == inf){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    n = N;
    dist.assign(n, vector<ll> (n, inf));    
    bfs({Sx-1, Sy-1});
    if(dist[Fx - 1][Fy - 1] != inf)
    return dist[Fx-1][Fy-1];
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int test_case;
	cin >> test_case;
    
	while (test_case--)
	{
        int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;
        fx = Fx-1, fy = Fy-1;
		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
