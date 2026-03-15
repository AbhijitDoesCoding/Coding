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

ll n; 
ll ans = 0;
vi p;
vi a;
vi primes;
void prePrime(){
    primes.assign(40,1);
    primes[0] = 0;
    primes[1] = 0;
    for(ll i = 2; i*i <= 39; i++){
        if(primes[i] == 1){
            for(ll j = i*i; j <= 39; j += i){
                primes[j] = 0;
            }
        }
    }
}

void rec(ll level){
    if(level == n){
        if(primes[p.back() + p[0]])
            ans++;
        return;
    }

    loop(i, 0, n){
        if(a[i] == 0){
            if(!primes[p.back() + (i+1)]) continue;
            a[i] = 1;
            p.pb(i+1);
            rec(level+1);
            p.pop_back();
            a[i] = 0;
        }
    }
}

void solve(){
    ans = 0;
    cin >> n; 
    if(n % 2 == 1 && n > 1){
        cout << 0;
        return;
    }
    p.clear();
    a.assign(n,0);
    prePrime();
    p.pb(1);
    a[0] = 1;
    rec(1);
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}