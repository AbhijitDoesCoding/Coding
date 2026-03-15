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

bool blocked[8][8];
ll ans;
vi p;

bool check(ll row,ll col){

    if(blocked[row][col]) return false;

    loop(i,0,row){
        if(p[i]==col || abs(i-row)==abs(p[i]-col)){
            return false;
        }
    }
    return true;
}

void rec(ll row){

    if(row==8){
        ans++;
        return;
    }

    loop(col,0,8){
        if(check(row,col)){
            p.pb(col);
            rec(row+1);
            p.pop_back();
        }
    }
}

void solve(){

    ans = 0;
    p.clear();

    loop(i,0,8){
        loop(j,0,8){
            char c;
            cin>>c;
            blocked[i][j] = (c=='*');
        }
    }

    rec(0);

    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    while(t--) solve();
    return 0;
}