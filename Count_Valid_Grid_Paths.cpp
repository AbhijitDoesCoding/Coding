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
string path;    
ll visited[7][7];
ll ans;

void rec(ll level, ll x, ll y){
    if(x == 6 && y == 0){
        if(level == 48) ans++;
        return;
    }
    if(level == 48) return;

    if((x==0 || visited[x-1][y]) &&
    (x==6 || visited[x+1][y]) &&
    (y>0 && !visited[x][y-1]) &&
    (y<6 && !visited[x][y+1])) return;

    if((y==0 || visited[x][y-1]) &&
    (y==6 || visited[x][y+1]) &&
    (x>0 && !visited[x-1][y]) &&
    (x<6 && !visited[x+1][y])) return;
    if(path[level] == '?'){
        if(x+1 < 7 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            rec(level+1, x+1, y);
            visited[x+1][y] = 0;
        }
        if(y+1 < 7  && visited[x][y+1] == 0){ 
            visited[x][y+1] = 1;
            rec(level+1, x, y+1);
            visited[x][y+1] = 0;
        }
        if(x-1 >= 0 && visited[x-1][y] == 0){ 
            visited[x-1][y] = 1;
            rec(level+1, x-1, y);
            visited[x-1][y] = 0;
        }
        if(y-1 >= 0 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            rec(level+1, x, y-1);
            visited[x][y-1] = 0;
        }
    }
    else if(path[level] == 'D'){
        if(x+1 < 7 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            rec(level+1, x+1, y);
            visited[x+1][y] = 0;
        }

    }
    else if(path[level] == 'U'){
        if(x-1 >= 0 && visited[x-1][y] == 0){ 
            visited[x-1][y] = 1;
            rec(level+1, x-1, y);
            visited[x-1][y] = 0;
        }
    }
    else if(path[level] == 'L'){
         if(y-1 >= 0 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            rec(level+1, x, y-1);
            visited[x][y-1] = 0;
        }
       
    }
    else if(path[level] == 'R'){
        if(y+1 < 7  && visited[x][y+1] == 0){ 
            visited[x][y+1] = 1;
            rec(level+1, x, y+1);
            visited[x][y+1] = 0;
        }
    }
    return;
}
void solve(){
    cin >> path;
    visited[0][0] = 1;
    rec(0, 0, 0);
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