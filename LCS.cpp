#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s, t;
ll n, m;
vector<vector<ll>> dp;

ll rec(ll i, ll j){
    if(i == n || j == m)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = 1 + rec(i + 1, j + 1);

    return dp[i][j] = max(rec(i + 1, j), rec(i, j + 1));
}

string ans;

void build(ll i, ll j){
    if(i == n || j == m)
        return;

    if(s[i] == t[j]){
        ans += s[i];
        build(i + 1, j + 1);
    }
    else if(rec(i + 1, j) >= rec(i, j + 1)){
        build(i + 1, j);
    }
    else{
        build(i, j + 1);
    }
}

void solve(){
    cin >> s >> t;

    n = s.size();
    m = t.size();

    dp.assign(n + 1, vector<ll>(m + 1, -1));

    rec(0, 0);

    ans.clear();
    build(0, 0);

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}