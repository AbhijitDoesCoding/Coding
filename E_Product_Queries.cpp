#include<bits/stdc++.h>
using namespace std; typedef long long ll;

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

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll binpow(ll b,ll p){ll a=1;for(b%=mod;p;p>>=1,b=b*b%mod) if(p&1)a=a*b%mod;return a;}
ll modinv(ll a){return binpow(a,mod-2);}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

void solve(){
    ll n; 
    cin >> n;

    vi a(n);
    loop(i,0,n) cin >> a[i];

    vi cnt(n+1,0);
    for(ll i : a) cnt[i]++;

    vi dp(n+1, inf);
    dp[1] = 0;

    vi vals;
    loop(v,2,n+1){
        if(cnt[v]) vals.pb(v);
    }

    loop(i, 1, n+1){
        if(dp[i] == inf) continue;
        for(ll v : vals){
            if(i * v > n) break;
            dp[i * v] = min(dp[i * v], dp[i] + 1);
        }
    }
    cout << ((cnt[1] > 0) ? "1" : "-1") << " ";
    loop(i,2,n+1){
            if(dp[i] == inf) cout << -1 << " ";
            else cout << dp[i] << " ";
    }
    nline;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
