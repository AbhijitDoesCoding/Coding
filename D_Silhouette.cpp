#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
// #define mp make_pair
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


void solve() {
    ll n;
    vector<ll> b, sb;
    cin >> n;
    b.resize(n);
    map<ll, ll> mp;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }
    
    if(mp.begin()->first != 0){
        cout << -1 << "\n";
        return;
    }

    vector<ll> u, c;
    for (auto const& it : mp) {
        u.pb(it.ff);
        c.pb(it.ss);
    }

    int k = u.size() - 1;
    vector<ll> ans(k + 1);

    if (k == 0) {
        ans[0] = 1;
    } else {
        for (int j = 0; j < k; j++) {
            ll diff = u[j+1] - u[j];
            
            if (diff % c[j] != 0) {
                cout << -1 << "\n";
                return;
            }
            
            ans[j] = diff / c[j];

            if (j > 0 && ans[j] <= ans[j-1]) {
                cout << -1 << "\n";
                return;
            }
        }
        ans[k] = ans[k-1] + 1;
    }

    unordered_map<ll, ll> sta;
    for (int i = 0; i <= k; i++) {
        sta[u[i]] = ans[i];
    }

    for (int i = 0; i < n; i++) {
        cout << sta[b[i]] << " ";
    }
    cout << "\n";

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}