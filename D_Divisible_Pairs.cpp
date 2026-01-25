#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> vc(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        freq[vc[i]]++;
    }

    long long count = 0;

    // Count pairs that satisfy the conditions
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((vc[i] + vc[j]) % x == 0 && (vc[i] - vc[j]) % y == 0) {
                count += freq[vc[i]] * freq[vc[j]];
            }
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
