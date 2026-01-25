#include <bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
    ll cnt = 0;
    vi a(n);
    ll ans = inf; // Initialize with a large value
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            cnt++;
        }
        ll rem = a[i] % k;
        if(rem != 0){
            rem = k - rem;
        }
        ans = min(ans, rem);
    }
    if (k == 4) {
        ll k = max(ll(0), 2 - cnt); 
        ans = min(ans, k);
        cout<<ans; 
        nline 
        return;
    } else if (k == 2) {
        cout << max(ll(0), 1 - cnt); 
        nline 
        return;
    }
    if (k == 3 || k == 5) {
        cout << ans; 
        nline 
        return;
    }
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
