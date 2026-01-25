#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    int open = 0, add = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            open++;
        }
        else
        {
            if (open > 0)
                open--; // matched with an opening
            else
                add++; // need to add an opening
        }
    }
    cout << open + add << "\n"; // unmatched opens + unmatched closes
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
