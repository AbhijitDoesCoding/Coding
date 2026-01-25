#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, d, l;
        cin >> n >> d >> l;

        // Invalid case checks
        if (l > n || d >= n || l > 2 * (d + 1)) {
            cout << -1 << endl;
            continue;
        }

        // If there are not enough leaves for the tree
        if (l == n && d != n - 1) {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int, int>> edges;

        // Construct a chain of length d (a path)
        for (int i = 1; i <= d; ++i) {
            edges.push_back({i, i + 1});
        }

        int leaves_needed = l - 2; // 2 leaves already in the path
        int node = d + 2;

        // Attach extra leaves to the end of the path
        for (int i = 0; i < leaves_needed; ++i) {
            edges.push_back({node, d + 1});
            node++;
        }

        // Attach non-leaf nodes
        int non_leaves_needed = n - 1 - leaves_needed;
        for (int i = 0; i < non_leaves_needed; ++i) {
            edges.push_back({d + 1, node});
            node++;
        }

        // Output the edges
        for (auto &e : edges) {
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}
