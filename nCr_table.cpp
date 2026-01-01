#include <bits/stdc++.h>

using namespace std;

#define int long long

int MOD = 1e9;
// int binpow(int a, int p)
// {
//     int res = 1;
//     a %= mod;
//     while (p > 0)
//     {
//         if (p & 1)
//             res = (res * a) % mod;
//         a = (a * a) % mod;
//         p >>= 1;
//     }
//     return res;
// }

// int inv(int a)
// {
//     return binpow(a, mod - 2);
// }

// int fact[1002], invfact[1002];

// void pre()
// {
//     fact[0] = 1;
//     for (int i = 1; i <= 1001; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
//     invfact[1001] = inv(fact[1001]);
//     for (int i = 1000; i >= 0; i--)
//     {
//         invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
//     }
// }

// int ncr(int n, int r)
// {
//     if (r < 0 || r > n)
//         return 0;
//     int num = fact[n];
//     int den = (invfact[r] * invfact[n - r]) % mod;
//     return (num * den) % mod;
// }

vector<int> solve(int n)
{
    
    vector<int> row(n + 1, 0);
    row[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            row[j] = (row[j] + row[j - 1]) % MOD;
        }
    }
    return row;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;

    // pre();
    while (t--)
    {
        int n;
        if (!(cin >> n))
            break;

        vector<int> result = solve(n);

        for (size_t i = 0; i < result.size(); i++)
        {
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}