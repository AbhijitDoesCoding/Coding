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

const int MAXN = 2e5 + 5;

struct node{
    ll val;
    node(){
        val = 0;
    }
    node(ll val){
        this->val = val;
    }
};

ll n, q; 
node tree[4 * MAXN];   
vi a;

node merge(node left, node right){
    node res = node();
    res.val = left.val ^ right.val;
    return res;
}

void build(ll index, ll low, ll high){
    if(low == high){
        tree[index] = node(a[low]);
        return;
    }
    ll mid = low + (high - low) / 2;
    build(2 * index, low, mid);
    build(2 * index + 1, mid + 1, high);
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

node query(ll index, ll low, ll high, ll l, ll r){
    if(r < low || high < l) return node(0);
    if(l <= low && high <= r) return tree[index];
    ll mid = low + (high - low) / 2;
    node left = query(2 * index, low, mid, l, r);
    node right = query(2 * index + 1, mid + 1, high, l, r);
    return merge(left, right);
}

void solve() {
    cin >> n >> q;
    a.resize(n);
    loop(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);
    for(int i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--, r--;
        node ans = query(1, 0, n - 1, l, r);
        cout << ans.val << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}