#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Knapsack {
private:
    vector<vector<ll>> B;
    vector<ll> weights;
    vector<ll> values;
    ll n, W;

public:
    Knapsack(ll n1, ll w1, vector<ll>& weights1, vector<ll>& values1) : n(n1), W(w1) {
        weights = weights1;
        values = values1;
        B.resize(n + 1, vector<ll>(W + 1, 0)); 
    }

    ll solve() {
        for (ll i = 1; i <= n; i++) {
            for (ll w = 1; w <= W; w++) {
                if (weights[i - 1] <= w) {
                    B[i][w] = max(values[i - 1] + B[i - 1][w - weights[i - 1]], B[i - 1][w]);
                } else {
                    B[i][w] = B[i - 1][w];
                }
            }
        }
        return B[n][W];
    }

    void findSelectedItems() {
        ll i = n, k = W;
        vector<ll> selectedItems;

        while (i > 0 && k > 0) {
            if (B[i][k] != B[i - 1][k]) {
                selectedItems.push_back(i);
                k -= weights[i - 1];
            }
            i--;
        }

        cout << "Selected items: ";
        for (ll i = selectedItems.size() - 1; i >= 0; i--) {
            cout << selectedItems[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ll n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity: ";
    cin >> W;

    vector<ll> weights(n), values(n);
    cout << "Enter weights and values of items:\n";
    for (ll i = 0; i < n; i++) {
        cout << "Item " << i + 1 << "\n";
        cout << "Weight: ";
        cin >> weights[i];
        cout << "Value: ";
        cin >> values[i];
    }

    Knapsack knapsack(n, W, weights, values);
    cout << "Maximum value that can be obtained: " << knapsack.solve() << "\n";
    knapsack.findSelectedItems();

    return 0;
}
