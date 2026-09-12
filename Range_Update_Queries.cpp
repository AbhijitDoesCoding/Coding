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

struct node{
    ll val;

    node(){
        val = 0;
    }

    node(ll val){
        this->val = val;
    }
};

node merge(node left, node right){
    node res;
    res.val = left.val + right.val;
    return res;
}

ll n, q;
node tree[4 * 200005];
ll lazy[4 * 200005];
vi a;

void build(int index, int low, int high){
    if(low == high){
        tree[index] = node(a[low]);
        return;
    }

    int mid = low + (high - low) / 2;

    build(2 * index, low, mid);
    build(2 * index + 1, mid + 1, high);

    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

void push(int index, int low, int high){
    if(lazy[index] == 0) return;

    if(low != high){
        int mid = low + (high - low) / 2;

        tree[2 * index].val += (mid - low + 1) * lazy[index];
        tree[2 * index + 1].val += (high - mid) * lazy[index];

        lazy[2 * index] += lazy[index];
        lazy[2 * index + 1] += lazy[index];
    }

    lazy[index] = 0;
}

void update(int index, int low, int high, int l, int r, ll val){
    if(r < low || high < l){
        return;
    }

    if(l <= low && high <= r){
        tree[index].val += (high - low + 1) * val;
        lazy[index] += val;
        return;
    }

    push(index, low, high);

    int mid = low + (high - low) / 2;

    update(2 * index, low, mid, l, r, val);
    update(2 * index + 1, mid + 1, high, l, r, val);

    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

node query(int index, int low, int high, int l, int r){
    if(r < low || high < l){
        return node(0);
    }

    if(l <= low && high <= r){
        return tree[index];
    }

    push(index, low, high);

    int mid = low + (high - low) / 2;

    node left = query(2 * index, low, mid, l, r);
    node right = query(2 * index + 1, mid + 1, high, l, r);

    return merge(left, right);
}

void solve(){
    cin >> n >> q;

    a.resize(n);

    loop(i, 0, n){
        cin >> a[i];
    }

    build(1, 0, n - 1);

    loop(i, 0, q){
        ll x;
        cin >> x;

        if(x == 1){
            int l, r;
            ll u;

            cin >> l >> r >> u;

            l--;
            r--;

            update(1, 0, n - 1, l, r, u);
        }
        else{
            int k;
            cin >> k;

            k--;

            node res = query(1, 0, n - 1, k, k);

            cout << res.val << "\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}