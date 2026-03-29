#include<bits/stdc++.h>
using namespace std; 
using i64 = long long;
using ld = long double;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define state pair<i64, i64>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const i64 N = 1e6 + 2, inf = 1e18, mod = 1e9 + 7;

i64 gcd(i64 a, i64 b) {
    return b == 0 ? a : gcd(b, a % b);
}

i64 lcm(i64 A, i64 B) {
    return A * (B / gcd(A, B));
}

i64 modexp(i64 a, i64 b) {               
    i64 res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 nCr(i64 n, i64 r) {
    if(r > n)
        return 0;
    if(r > n - r)
        r = n - r;
    i64 res = 1;
    for(i64 i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) % mod;              
        res = (res * modexp(i, mod - 2)) % mod;       
    }
    return res;
}

void solve(){
    i64 p, q;
    cin >> p >> q;

    const i64 INF = 1e18;

    vector<vector<i64>> dp(2, vector<i64>(2, INF));
    dp[0][0] = 0;

    for(int i = 0; i < 62; i++){
        vector<vector<i64>> ndp(2, vector<i64>(2, INF));

        for(int c1 = 0; c1 < 2; c1++){
            for(int c2 = 0; c2 < 2; c2++){
                if(dp[c1][c2] == INF) continue;

                for(int kbit = 0; kbit <= 1; kbit++){
                    i64 pb = (p >> i) & 1;
                    i64 qb = (q >> i) & 1;

                    i64 s1 = pb + kbit + c1;
                    i64 s2 = qb + kbit + c2;

                    i64 b1 = s1 & 1;
                    i64 b2 = s2 & 1;

                    if(b1 == 1 && b2 == 1) continue;

                    int nc1 = s1 >> 1;
                    int nc2 = s2 >> 1;

                    i64 val = dp[c1][c2] + ((i64)kbit << i);

                    ndp[nc1][nc2] = min(ndp[nc1][nc2], val);
                }
            }
        }
        dp = ndp;
    }

    i64 ans = INF;
    for(int c1 = 0; c1 < 2; c1++){
        for(int c2 = 0; c2 < 2; c2++){
            ans = min(ans, dp[c1][c2]);
        }
    }

    if(ans == INF) cout << "NO\n";
    else cout << "YES " << ans << "\n";
}

int32_t main() {
    IOS 
    i64 tc = 1;
    cin >> tc;
    while(tc--) {
        solve();
    }
}