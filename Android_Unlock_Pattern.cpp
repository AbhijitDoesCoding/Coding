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

bool visited[10];
ll skipv[10][10];

ll dfs(ll cur, ll rem){
    if(rem==0) return 1;

    visited[cur]=true;
    ll ans=0;

    loop(i,1,10){
        if(!visited[i] && (!skipv[cur][i] || visited[skipv[cur][i]])){
            ans += dfs(i,rem-1);
        }
    }

    visited[cur]=false;
    return ans;
}

void solve(){
    ll n;
    cin>>n;

    memset(visited,false,sizeof(visited));
    memset(skipv,0,sizeof(skipv));

    skipv[1][3]=skipv[3][1]=2;
    skipv[1][7]=skipv[7][1]=4;
    skipv[3][9]=skipv[9][3]=6;
    skipv[7][9]=skipv[9][7]=8;

    skipv[1][9]=skipv[9][1]=5;
    skipv[2][8]=skipv[8][2]=5;
    skipv[3][7]=skipv[7][3]=5;
    skipv[4][6]=skipv[6][4]=5;

    ll ans=0;

    ans += dfs(1,n-1)*4;
    ans += dfs(2,n-1)*4;
    ans += dfs(5,n-1);

    cout<<ans;
    nline;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}