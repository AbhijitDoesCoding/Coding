#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define all(x) x.begin(), x.end()
#define pb push_back
#define mod 1000000007
#define inf 1e18
#define loop(i, l, h) for (int i = l; i < h; i++)

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

struct new_struct
{
    multiset<ll> a;
    ll sum = 0;

    void add(ll x)
    {
        a.insert(x);
        sum += x;
    }

    void remove(ll x)
    {
        auto it = a.find(x);
        if (it != a.end())
        {
            a.erase(it);
            sum -= x;
        }
    }

    ll get_min() const
    {
        return a.empty() ? -1 : *a.begin();
    }

    ll get_max() const
    {
        return a.empty() ? -1 : *a.rbegin();
    }

    ll get_sum() const
    {
        return sum;
    }
};

void solve()
{
    ll n;
    cin >> n;
    new_struct ns;

    loop(i, 0, n)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            ns.add(x);
        }
        else if (type == 2)
        {
            ll x;
            cin >> x;
            ns.remove(x);
        }
        else if (type == 3)
        {
            char ignore;
            cin >> ignore; // reads '?'
            cout << ns.get_min() << "\n";
        }
        else if (type == 4)
        {
            char ignore;
            cin >> ignore; // reads '?'
            cout << ns.get_max() << "\n";
        }
        else if (type == 5)
        {
            char ignore;
            cin >> ignore; // reads '?'
            cout << ns.get_sum() << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
