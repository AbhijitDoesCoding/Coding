#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

unordered_map<ll,ll> mp;
int n, m;
vector<ll> a;
vector<string> dp;
vector<int> vis;

string rec(int i){
    if(i == 0) return "";
    if(i < 0) return "#";

    if(vis[i]) return dp[i];
    vis[i] = 1;

    string ans = "#";

    for(int j = 0; j < m; j++){
        string nxt = rec(i - mp[a[j]]);

        if(nxt == "#") continue;

        string temp = to_string(a[j]) + nxt;

        if(ans == "#" ||
           temp.size() > ans.size() ||
           (temp.size() == ans.size() && temp > ans)){
            ans = temp;
        }
    }

    return dp[i] = ans;
}

void solve() {
    mp[1] = 2;
    mp[2] = 5;
    mp[3] = 5;
    mp[4] = 4;
    mp[5] = 5;
    mp[6] = 6;
    mp[7] = 3;
    mp[8] = 7;
    mp[9] = 6;

    cin >> n >> m;

    a.resize(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];

    sort(rall(a));

    dp.assign(n + 1, "");
    vis.assign(n + 1, 0);

    cout << rec(n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}