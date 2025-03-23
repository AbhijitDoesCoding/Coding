#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    ll u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<ll> parent, sz;

ll find(ll x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(ll x, ll y) {
    ll rootX = find(x);
    ll rootY = find(y);

    if (rootX != rootY) {
        if (sz[rootX] < sz[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        sz[rootX] += sz[rootY];
    }
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> x(n), a(n);
    for (ll i = 0; i < n; i++) cin >> x[i];
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<Edge> edges;

    for (ll u = 0; u < n; u++) {
        for (ll v = u + 1; v < n; v++) {
            ll dist = abs(x[u] - x[v]);
            ll threadCost = min(a[u], a[v]);
            edges.push_back({u, v, dist * threadCost});
        }
    }

    sort(edges.begin(), edges.end());

    parent.resize(n);
    sz.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);

    ll totalCost = 0;
    ll edgesUsed = 0;

    for (const auto& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            union_sets(edge.u, edge.v);
            totalCost += edge.cost;
            edgesUsed++;

            if (edgesUsed == n - 1) break;
        }
    }

    cout << totalCost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
