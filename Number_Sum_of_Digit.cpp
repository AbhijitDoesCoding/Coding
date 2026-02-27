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

bool check(ll mid, ll s){
    ll sum = mid;
    while(mid > 0){
        sum -= mid % 10;
        mid /= 10;
    }
    
    return sum >= s;
}

void solve(){
    ll n, s; 
    cin >> n >> s;
    ll low = 1, high = n;
    ll ans = -1;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        if(check(mid, s)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }  
    if(ans == -1){
        cout << 0; nline;
    }
    else{
        cout << n - ans + 1; nline;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}