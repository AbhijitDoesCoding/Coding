#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> original(n);
    set<int> foundSet;
    multiset<int> missingValues;
    for (int i = 0; i < n; ++i) {
        cin >> original[i];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        foundSet.insert(x);
        if (original[i] != x)
            missingValues.insert(x);
    }

    int m;
    cin >> m;
    bool all_done = false;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (missingValues.find(x) != missingValues.end()) {
            missingValues.erase(missingValues.find(x));
            if (i == m - 1)
                all_done = true;
        } else if (foundSet.count(x)) {
            if (i == m - 1)
                all_done = true;
        }
    }

    if (all_done && missingValues.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_tests;
    cin >> total_tests;
    while (total_tests--) {
        solve();
    }
    return 0;
}
