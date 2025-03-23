#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool canSortPermutation(const vector<int>& p, const string& s, int n) {
    // We are interested in the positions where we can swap based on L and R
    int minL = n + 1;  // Track the rightmost "L"
    int maxR = -1;     // Track the leftmost "R"

    // Traverse the permutation from left to right
    for (int i = 0; i < n - 1; ++i) {
        if (p[i] > p[i + 1] && s[i + 1] != 'L') {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        string s;
        cin >> s;

        // Process each query
        for (int i = 0; i < q; ++i) {
            int idx;
            cin >> idx;
            --idx; // convert to zero-indexed

            // Toggle s[idx]
            s[idx] = (s[idx] == 'L') ? 'R' : 'L';

            // Check if the permutation can be sorted with the current string s
            if (canSortPermutation(p, s, n)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}