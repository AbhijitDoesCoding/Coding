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

bool check(long double mid, vi &speed, vi &x, ll n){
    long double left = -1e18, right = 1e18;

    for(ll i = 0; i < n; i++){
        left = max(left, (long double)x[i] - (long double)speed[i] * mid);
        right = min(right, (long double)x[i] + (long double)speed[i] * mid);
    }

    return left <= right;
}

void solve() {
    ll n; cin >> n; 
    vi x(n);
    for(ll i = 0; i < n; i++) cin >> x[i];

    vi speed(n);
    for(ll i = 0; i < n; i++) cin >> speed[i];

    long double low = 0, high = 1e9;
    long double eps = 1e-7;

    while(high - low > eps){
        long double mid = (low + high) / 2;
        if(check(mid, speed, x, n)){
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(12) << high << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}