#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define loop(i, l, h) for (int i = l; i < h; i++)

void solve()
{
    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    loop(i, 0, n)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll ans = 0;
    while (pq.size() > 1)
    {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        ll sum = x + y;
        ans += sum;
        pq.push(sum);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
