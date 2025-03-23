#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcn;
    cin >> tcn;
    
    while (tcn--) {
        int n;
        cin >> n;

        vector<int> l(n);
        for (int i = 0; i < n; ++i) {
            l[i] = i + 1;
        }

        for (const auto& val : l) {
            cout << val << ' ';
        }
        cout << '\n';

        int mid = (n + 1) / 2;
        vector<int> rearranged(l.begin() + mid, l.end());
        rearranged.insert(rearranged.end(), l.begin(), l.begin() + mid);

        for (const auto& val : rearranged) {
            cout << val << ' ';
        }
        cout << '\n';
    }

return 0;
}