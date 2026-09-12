#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

ll binpow(ll b, ll p) {
    ll a = 1;

    for (b %= mod; p; p >>= 1, b = b * b % mod)
        if (p & 1) a = a * b % mod;

    return a;
}

ll modinv(ll a) {
    return binpow(a, mod - 2);
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

const int MAXN = 4e5 + 5;

struct node {
    ll val;

    node(ll val = 0) {
        this->val = val;
    }
};

ll n, q;

vi a;
vi values;

node tree[MAXN];

int getIndex(ll x) {
    return lower_bound(all(values), x) - values.begin() + 1;
}

void update(int index, ll val) {
    while(index <= values.size()) {
        tree[index].val += val;
        index += index & -index;
    }
}

ll query(int index) {
    ll ans = 0;

    while(index > 0) {
        ans += tree[index].val;
        index -= index & -index;
    }

    return ans;
}

ll query(ll l, ll r) {
    int left = lower_bound(all(values), l) - values.begin();
    int right = upper_bound(all(values), r) - values.begin();

    return query(right) - query(left);
}

void solve() {
    cin >> n >> q;

    a.resize(n);

    loop(i, 0, n) {
        cin >> a[i];
        values.pb(a[i]);
    }

    vector<tuple<char,ll,ll>> queries(q);

    loop(i, 0, q) {
        char type;
        ll x, y;

        cin >> type >> x >> y;

        queries[i] = {type, x, y};

        if(type == '!') {
            values.pb(y);
        }
    }

    sort(all(values));
    values.erase(unique(all(values)), values.end());

    loop(i, 0, n) {
        update(getIndex(a[i]), 1);
    }

    for(auto [type, x, y] : queries) {

        if(type == '!') {
            int k = x - 1;

            update(getIndex(a[k]), -1);

            a[k] = y;

            update(getIndex(a[k]), 1);
        }

        else if(type == '?') {
            cout << query(x, y) << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;
}