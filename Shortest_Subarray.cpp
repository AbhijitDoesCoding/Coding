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

void solve(){
    ll n; cin >> n; 
    vi a(n);
    unordered_map<ll, ll> freq;
    ll distinct = 0;
    loop(i,0,n){ 
        cin >> a[i];
        freq[a[i]]++;
        if(freq[a[i]] == 1) distinct++;
    }
    ll tail = 0, head = -1;
    unordered_map<ll, ll> freq_window;
    ll distinct_window = 0;

    ll ans = inf; 

    while(tail < n){
        while(head + 1 < n && distinct_window < distinct){
            head++;
            if(freq_window[a[head]] == 0) distinct_window++;
            freq_window[a[head]]++;
        }
        if(distinct_window == distinct) ans = min(ans, head - tail + 1);
        if(tail > head){
            tail++;
            head = tail - 1;
        }
        else{
            if(freq_window[a[tail]] == 1) distinct_window--;
            freq_window[a[tail]]--;
            tail++;
        }
    }
    cout << ans; 
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