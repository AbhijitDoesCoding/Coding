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

ll n, m, k; 
vi a, b;

bool check(ll mid){
    ll count = 0;
    for(int i = 0; i < n; i++){
        count += upper_bound(all(b), mid - a[i]) - b.begin();
    }
    return count >= k;
}

void solve(){
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    loop(i,0,n) cin >> a[i];
    loop(i,0,m) cin >> b[i];
    if(n > m) swap(a, b), swap(n, m);
    sort(all(a));
    sort(all(b));
    ll low = a[0] + b[0], high = a[n-1] + b[m-1];
    ll ans = high; 
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
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