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
ll k; 
vector<char> p;
ll op, cl;
bool checkDepth(){
    ll cur = 0;
    ll best = 0;

    loop(i,0,n){
        if(p[i] == '('){
            cur++;
            best = max(best, cur);
        }
        else{
            cur--;
        }
    }

    return best == k;
}
void rec(ll col){
    if(col == n){
    {
        if(checkDepth()){
            loop(i,0,n){
                    cout << p[i];
                }
                nline;
            }
        }
        return;
    }

    if(op < n/2){
        p[col] = '(';
        op++;
        rec(col+1);
        op--;
    }

    if(cl < op){
        p[col] = ')';
        cl++;
        rec(col+1);
        cl--;
    }
}
void solve(){
    cin >> n >> k;
    op = 0;
    cl = 0;
   
    p.resize(n);
    rec(0);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}