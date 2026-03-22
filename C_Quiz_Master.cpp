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

void solve() {
    ll n, m; 
    cin >> n >> m;

    vi ss(n);
    loop(i,0,n) cin >> ss[i];

    sort(all(ss));

    vector<vector<ll>> divs(n);

    loop(i,0,n){
        for(ll d = 1; d * d <= ss[i]; d++){
            if(ss[i] % d == 0){
                if(d <= m) divs[i].pb(d-1);
                if(d != ss[i]/d && ss[i]/d <= m)
                    divs[i].pb((ss[i]/d)-1);
            }
        }
    }

    vi freq(m, 0);
    ll distinct = 0;

    ll tail = 0, head = -1;
    ll ans = inf;

    while(tail < n){

        while(head + 1 < n && distinct < m){
            head++;

            for(auto d : divs[head]){
                if(freq[d] == 0) distinct++;
                freq[d]++;
            }
        }

        if(distinct == m){
            ans = min(ans, ss[head] - ss[tail]);
        } else {
            break; 
        }

        for(auto d : divs[tail]){
            freq[d]--;
            if(freq[d] == 0) distinct--;
        }

        tail++;
    }

    if(ans == inf) ans = -1;
    cout << ans;
    nline;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}