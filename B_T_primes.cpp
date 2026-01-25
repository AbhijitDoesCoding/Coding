#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout<<"\n";
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
ll binpow(ll b,ll p, ll mod1){ll ans=1;b%=mod1;for(;p;p>>=1){if(p&1)ans=ans*b%mod1;b=b*b%mod1;}return ans;}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

vi prime(1001000, 1);

void sieve(){
    prime[0] = 0;
    prime[1] = 0;
    for(ll i = 2; i * i <= 1001000; i++){
        if(prime[i] == 1){
            for(ll j = i * i; j <= 1001000; j += i){
                prime[j] = 0;
            }
        }
    }
}


void solve(){
    ll n; cin >> n;
    vi a(n);
    loop(i, 0, n){
        cin >> a[i];
        ll r = round(sqrt(a[i]));
        if (r * r == a[i] && prime[r] == 1)
        {
            yes;
        }
        else
        {
            no;
        }
    }

    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll t = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}