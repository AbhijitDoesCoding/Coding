#include<bits/stdc++.h>
using namespace std; typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define ff first
#define ss second
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll binpow(ll b,ll p){ll a=1;for(b%=mod;p;p>>=1,b=b*b%mod) if(p&1)a=a*b%mod;return a;}
ll modinv(ll a){return binpow(a,mod-2);}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

ll dist(ll e, ll f, ll i, ll x, ll y){
    ll ans = 0;
    ans += (i - e);
    ans += min(abs(f - x), abs(f - y));
    ans += abs(x - y);
    return ans;
}

void solve(){
    ll n; cin >> n;
    ll a, b; cin >> a >> b;
    ll c, d; cin >> c >> d;

    vi x(n);
    set<ll> s;
    loop(i, 0, n){
        cin >> x[i];
        s.insert(x[i]);
    }

    vector<pair<ll, ll>> v;
    loop(i, 0, n){
        ll z; cin >> z;
        v.pb({x[i], z});
    }

    sort(all(v));

    unordered_map<ll, pair<ll,ll>> mp;

    for(auto i : v){
        if(mp.find(i.ff) == mp.end()){
            mp[i.ff] = {i.ss, i.ss};
        } else {
            mp[i.ff].ff = min(mp[i.ff].ff, i.ss);
            mp[i.ff].ss = max(mp[i.ff].ss, i.ss);
        }
    }

    ll ans = 0;
    ll e = a, f = b;
    ll lastx = a, lasty = b;

    for(auto i : s){
        ll k = dist(e, f, i, mp[i].ff, mp[i].ss);
        ans += k;

        e = i;
        if(abs(f - mp[i].ff) < abs(f - mp[i].ss)){
            f = mp[i].ss;
        } else {
            f = mp[i].ff;
        }

        lastx = i;
        lasty = f;
    }

    ans += dist(lastx, lasty, c, d, d);
    cout << ans;
    nline;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
