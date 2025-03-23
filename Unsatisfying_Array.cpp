#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    
    vector<tuple<ll, ll, ll>> constraints(k);
    
    // Reading the constraints
    for (ll i = 0; i < k; ++i) {
        ll l, r, m;
        cin >> l >> r >> m;
        constraints[i] = {l, r, m};
    }

    // The resulting array
    vector<ll> A(n + 1, 0);
    
    // Initializing array with a large value that won't interfere
    for (ll i = 1; i <= n; ++i) {
        A[i] = n + 1;
    }

    // Start assigning values from bottom to top
    for (ll i = n; i >= 1; --i) {
        bool valid = false;
        
        // Try assigning the largest possible value first (prefer higher values)
        for (ll val = n; val >= 1; --val) {
            A[i] = val;
            
            // Check all constraints to see if we are violating the minimum condition
            bool violates = false;
            for (auto &[l, r, m] : constraints) {
                // If this range contains the current index and the minimum of the range is m
                if (l <= i && i <= r) {
                    if (*min_element(A.begin() + l, A.begin() + r + 1) == m) {
                        violates = true;
                        break;
                    }
                }
            }

            // If no violation, break and proceed to next index
            if (!violates) {
                valid = true;
                break;
            }
        }

        if (!valid) {
            cout << -1 << "\n";
            return;
        }
    }

    // Output the valid array
    for (ll i = 1; i <= n; ++i) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
