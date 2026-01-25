#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nline cout << "\n";
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i, l, h) for (int i = l; i < h; i++)
#define rev(i, l, h) for (int i = h - 1; i >= l; i--)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

void solve() {
    ll n;
    cin >> n;
    vector<pi> uk;
    vector<vi> uzi;
    ll mini = inf;  // Use inf as the initial minimum value
    
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        vi v(x);
        for (ll j = 0; j < x; j++) {
            cin >> v[j];
        }
        sort(all(v));
        mini = min(v[0], mini);
        uzi.pb(v);
        uk.pb(mp(v[1], i));
    }
    
    sort(all(uk));
    
    ll total = 0;
    for (ll i = 1; i < n; i++) {
        total += uk[i].ff;
    }
    total += mini;
    
    cout << total; 
    nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
