#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> a;
ll dp[100005][2];
bool vis[100005][2];

ll rec(int i, int flip){
    if(vis[i][flip]) return dp[i][flip];
    vis[i][flip] = true;

    ll cur = flip ? -a[i] : a[i];

    if(i == n - 1){
        return dp[i][flip] = cur;
    }

    ll ans = cur + rec(i + 1, 0);

    ans = max(ans, -cur + rec(i + 1, 1));

    return dp[i][flip] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << rec(0, 0) << '\n';
    return 0;
}