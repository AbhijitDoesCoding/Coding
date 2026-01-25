#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        bool found = false;
        vector<int> indices;

        // Check every possible non-empty subset
        for (int mask = 1; mask < (1 << N); ++mask) {
            int currentAND = -1; // Start with -1 to initialize AND
            indices.clear(); // Reset the indices for each subset

            // Form the subset and calculate its AND
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {  // If i-th bit is set, include arr[i]
                    indices.push_back(i + 1);  // Store 1-based index
                    if (currentAND == -1) {
                        currentAND = arr[i]; // Initialize the AND with the first element
                    } else {
                        currentAND &= arr[i]; // Perform the AND with the current element
                    }
                }
            }

            // If the AND equals K, we found a valid subset
            if (currentAND == K) {
                found = true;
                break; // Stop early as we found a valid subset
            }
        }

        // Output the result
        if (found) {
            cout << "YES\n";
            cout << indices.size() << '\n';
            for (int idx : indices) {
                cout << idx << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
