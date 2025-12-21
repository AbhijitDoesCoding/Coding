#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define loop(i, l, h) for (int i = l; i < h; i++)

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll binpow(ll b, ll p, ll mod1)
{
    ll ans = 1;
    b %= mod1;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b % mod1;
        b = b * b % mod1;
    }
    return ans;
}

ll modinv(ll x)
{
    return binpow((x % mod + mod) % mod, mod - 2, mod);
}

vi waterfill(vi vals, ll rem)
{
    int s = vals.size();
    for (int i = 0; i < s - 1 && rem > 0; i++)
    {
        ll need = (ll)(i + 1) * (vals[i + 1] - vals[i]);
        if (need <= rem)
        {
            for (int j = 0; j <= i; j++)
                vals[j] = vals[i + 1];
            rem -= need;
        }
        else
        {
            ll add = rem / (i + 1);
            for (int j = 0; j <= i; j++)
                vals[j] += add;
            rem -= add * (i + 1);
            for (int j = 0; j < rem; j++)
                vals[j]++;
            rem = 0;
            break;
        }
    }
    if (rem > 0)
    {
        ll add = rem / s;
        for (int i = 0; i < s; i++)
            vals[i] += add;
        for (int i = 0; i < rem % s; i++)
            vals[i]++;
    }
    return vals;
}

void solve()
{
    ll n, K;
    cin >> n >> K;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    vector<pair<ll, int>> arr(n);
    loop(i, 0, n) arr[i] = {a[i], i};
    sort(all(arr));

    priority_queue<pair<ll, int>> pq;
    multiset<ll> unused(a.begin(), a.end());
    vi cur = a;
    vector<char> used(n, 0);
    int p = 0;
    ll cost = 0;
    ll prod = 1, best = 0;
    double bestLog = -1e300;
    for (auto x : a)
        prod = prod * ((x + 1) % mod) % mod;

    loop(mex, 0, n)
    {
        while (p < n && arr[p].first <= mex)
            pq.emplace(arr[p].first, arr[p].second), p++;
        if (pq.empty())
            break;
        auto [val, idx] = pq.top();
        pq.pop();
        unused.erase(unused.find(val));
        used[idx] = 1;
        cur[idx] = mex;
        cost += mex - val;
        if (cost > K)
            break;
        prod = prod * ((mex + 1) % mod) % mod * modinv((val + 1) % mod) % mod;
        ll rem = K - cost;

        if (!unused.empty())
        {
            vi vals(unused.begin(), unused.end()), fvals = waterfill(vals, rem);
            ll mult = 1;
            loop(i, 0, vals.size()) mult = mult * ((fvals[i] + 1) % mod) % mod * modinv((vals[i] + 1) % mod) % mod;
            ll cand = (mex + 1) % mod * prod % mod * mult % mod;
            double l = log((double)(mex + 1));
            loop(i, 0, n) if (used[i]) l += log((double)(cur[i] + 1));
            for (auto fv : fvals)
                l += log(fv + 1);
            if (l > bestLog)
                bestLog = l, best = cand;
        }
        else
        {
            loop(i, 0, n) if (used[i])
            {
                ll v = cur[i];
                if (v == 0)
                    continue;
                ll numer = (v + rem + 1) % mod, denom = (v + 1) % mod;
                ll cand = v * prod % mod * numer % mod * modinv(denom) % mod;
                double l = log((double)v);
                loop(j, 0, n) l += log(cur[j] + 1);
                l += log(v + rem + 1) - log(v + 1);
                if (l > bestLog)
                    bestLog = l, best = cand;
            }
        }
    }
    cout << (best % mod + mod) % mod << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
