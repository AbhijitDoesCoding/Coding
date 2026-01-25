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
    vi v(n);
    loop(i, 0, n) cin >> v[i];
    vector<pi> pie(n);  // Initialize pie with size n
    loop(i, 0, n) {
        ll x;
        cin >> x;
        pie[i] = mp(x, v[i]);  // Properly initialize pie
    }
    sort(all(pie));
    ll cost = k;  // Initial cost
    ll count = n - 1;
    ll j = 0;
    while (count > 0 && j < n) {
        if (pie[j].ff >= k) {
            cost += k * count;
            break;
        } else {
            if (pie[j].ss > 0) {
                ll x = min(pie[j].ss, count);
                cost += pie[j].ff * x;
                count -= x;
            }
            j++;
        }
    }
    cout << cost; 
    nline;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
