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

void solve(){
    ll n; cin >> n; 
    vi a(n);
    loop(i,0,n) cin >> a[i];
    unordered_map<ll,ll> mp;
    for(auto i : a) mp[i]++;
    ll bestlen = 0;
    ll bestl = -1, bestr = -1;
    ll curStart = -1; 
    ll curLen = 0;
    loop(i, 0, n){
        if(mp[a[i]] == 1){
            if(curStart == -1) {curStart = i; curLen = 1;}
            else curLen++;
        }
        else{
            if(curLen > bestlen){
                bestlen = curLen;
                bestl = curStart;
                bestr = i-1;
            }
            curStart = -1;
            curLen = 0;
        }
    }
    if(curLen > bestlen){
        bestlen = curLen;
        bestl = curStart;
        bestr = n - 1;
    }
    if(bestlen > 0){
        cout << bestl+1 << " " << bestr+1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}