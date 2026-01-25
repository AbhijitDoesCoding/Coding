#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define loop(i, l, h) for (int i = l; i < h; i++)
#define mod 1000000007

const int MAXB = 63;
ll matPow[MAXB][3][3];

void mulMat(ll A[3][3], ll B[3][3], ll C[3][3])
{
    ll temp[3][3]{};
    loop(i, 0, 3) loop(j, 0, 3) loop(k, 0, 3)
        temp[i][j] = (temp[i][j] + A[i][k] * B[k][j] % mod) % mod;
    loop(i, 0, 3) loop(j, 0, 3) C[i][j] = temp[i][j];
}

void mulMatVec(ll A[3][3], ll v[3], ll res[3])
{
    ll temp[3]{0};
    loop(i, 0, 3) loop(j, 0, 3)
        temp[i] = (temp[i] + A[i][j] * v[j] % mod) % mod;
    loop(i, 0, 3) res[i] = temp[i];
}

void pre()
{
    ll mat[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    loop(i, 0, 3) loop(j, 0, 3) matPow[0][i][j] = mat[i][j];
    loop(p, 1, MAXB) mulMat(matPow[p - 1], matPow[p - 1], matPow[p]);
}

ll trib(ll n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    ll v[3] = {1, 1, 0}, res[3]{};
    unsigned long long e = n - 3;
    loop(p, 0, MAXB)
    {
        if (e & (1ULL << p))
        {
            mulMatVec(matPow[p], v, res);
            loop(i, 0, 3) v[i] = res[i];
        }
    }
    return v[0];
}

void solve()
{
    ll n;
    cin >> n;
    cout << trib(n) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pre();
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
