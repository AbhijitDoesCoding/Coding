#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    string s;
    cin >> s;


    bool allSame = true;
    for (int i = 1; i < n; ++i)
        if (s[i] != s[0])
        {
            allSame = false;
            break;
        }
    if (allSame)
    {
        cout << 1LL * n * (n + 1) / 2 << "\n";
        return 0;
    }

    vector<int> present(256, 0);
    for (char ch : s)
        present[(unsigned char)ch] = 1;

    ll ans = 0;

    ans += 1;

    for (int x = 0; x < 256; ++x)
    {
        if (!present[x])
            continue;
        char X = (char)x;

        int firstNotX = -1, lastNotX = -1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != X)
            {
                firstNotX = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != X)
            {
                lastNotX = i;
                break;
            }
        }


        if (firstNotX == -1)
            continue;

        ll coverAllNonX = 1LL * (firstNotX + 1) * (n - lastNotX);
        
        ans += (coverAllNonX - 1);
    }

    cout << (ans % 998244353 + 998244353) % 998244353 << "\n";
    return 0;
}
