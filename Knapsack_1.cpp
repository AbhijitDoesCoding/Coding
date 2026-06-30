#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, W;
vector<ll> wt, val;
vector<vector<ll>> dp;

ll knapsack(ll i, ll rem) {

    if(i == n) return 0;

    if(dp[i][rem] != -1)
        return dp[i][rem];

    ll ans = knapsack(i + 1, rem); // skip

    if(wt[i] <= rem) {
        ans = max(ans,
                  val[i] + knapsack(i + 1, rem - wt[i]));
    }

    return dp[i][rem] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;

    wt.resize(n);
    val.resize(n);

    for(ll i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    dp.assign(n, vector<ll>(W + 1, -1));

    cout << knapsack(0, W) << '\n';
}