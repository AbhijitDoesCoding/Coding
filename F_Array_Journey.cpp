#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define loop(i, l, h) for (ll i = l; i < h; i++)

typedef vector<ll> vi;

void solve() {
    ll n;
    cin >> n;
    vi a(n);
    loop(i, 0, n) cin >> a[i];
    ll k;
    cin >> k;

    deque<ll> dq;
    vi dp(n, -1);

    dp[n - 1] = a[n - 1];
    dq.push_back(n - 1);

    for (ll i = n - 2; i >= 0; --i) {
        while (!dq.empty() && dq.front() > i + k) {
            dq.pop_front();
        }

        dp[i] = a[i] + dp[dq.front()];

        while (!dq.empty() && dp[dq.back()] <= dp[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << dp[0];
    nline;
}

signed main() {
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
