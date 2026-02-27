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

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;} ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
ll ceil_div(ll a,ll b){return (a+b-1)/b;}
ll binpow(ll b,ll p){ll a=1;for(b%=mod;p;p>>=1,b=b*b%mod) if(p&1)a=a*b%mod;return a;}
ll modinv(ll a){return binpow(a,mod-2);}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

bool check(ll mid, vi &prefix, ll k){
    for(ll i = mid - 1; i < prefix.size(); i++){
        if(mid - (prefix[i] - (i - mid >= 0 ? prefix[i - mid] : 0)) <= k){
            return true;
        }
    }
    return false;
}
void solve(){
    ll n, k; 
    cin >> n >> k;
    vi a(n);
    loop(i,0,n) cin >> a[i];
    vi prefix(n);
    prefix[0] = a[0];
    loop(i,1,n) prefix[i] = prefix[i-1] + a[i];
    ll low = 0, high = n;
    ll ans = 0;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(mid, prefix, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}