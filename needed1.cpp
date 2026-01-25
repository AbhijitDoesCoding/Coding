#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

typedef pair<ll, ll> pl;

void solve() {
    ll n;
    cin >> n;

    vector<ll> x(n), a(n);
    for (ll i = 0; i < n; i++) cin >> x[i];
    for (ll i = 0; i < n; i++) cin >> a[i];

    priority_queue<pl, vector<pl>, greater<pl>> pq;
    vector<bool> vis(n, false);
    ll totalCost = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;

        vis[u] = true;
        totalCost += cost;

        for (ll v = 0; v < n; v++) {
            if (!vis[v] && u != v) {
                ll dist = abs(x[u] - x[v]);
                ll threadCost = min(a[u], a[v]);
                pq.push({dist * threadCost, v});
            }
        }
    }

    cout << totalCost << "\n";
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
