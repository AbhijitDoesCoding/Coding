#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, s;
    cin >> k >> s;
    int ans = 0;
    // to ensure s-z is below 2*k
    int st = max(0, s - 2 * k);
    // to ensure s-z is greater than equal to 0
    int end = min(k, s);
    for (int z = st; z <= end; z++) // loop for all possible values of x
    {
        int rem = s - z;
        if (rem > k)
            ans += (2 * k - rem + 1);
        else
            ans += (rem + 1);
    }
    cout << ans << "\n";

    return 0;
}
