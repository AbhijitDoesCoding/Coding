#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i, l, h) for(int i = l; i < h; i++)
typedef vector<ll> vi;

void solve() {
    ll n; cin >> n;
    vi v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    ll ans = -1000000007;

    // Condition 2: Chosen subarray contains an and a1
    for (int i = 0; i < n; ++i) {
        ans = max(ans, v[(i - 1 + n) % n] - v[i]);
    }

    // Condition 3: Chosen subarray doesn't contain an
    for (int i = 1; i < n; ++i) {
        ans = max(ans, v[i] - v[0]);
    }

    // Condition 4: Chosen subarray doesn't contain a1
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, v[n - 1] - v[i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
