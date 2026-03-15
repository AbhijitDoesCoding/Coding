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

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        ll n, d;
        cin >> n >> d;
        if(!n && !d) break;

        map<ll,ll> M;

        for(ll i = 2; i * i <= n; i++){
            ll cnt = 0;
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            if(cnt) M[i] += 2 * cnt;
        }

        if(n > 1) M[n] += 2;

        M[2] += 2 * d;
        M[5] += 2 * d;

        ll ans = 1;
        bool sqr = true;
        ll MOD = 1000007;

        for(auto it : M){
            ans = (ans * (it.ss + 1)) % MOD;
            if(it.ss % 2) sqr = false;
        }

        ans = (ans * 2) % MOD;
        if(sqr)
            ans = (ans - 1 + MOD) % MOD;

        cout << ans;
        nline;
    }

    return 0;
}