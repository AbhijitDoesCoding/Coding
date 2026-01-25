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

ll n2plusn(ll x)
{
    ll d = 1 + 4 * x;
    ll s = sqrt(d);
    // if (s * s != d)
    //     return -1; // no integer solution
    // if ((s - 1) % 2 != 0)
    //     return -1;
    return (s + 1)/2;
}

void solve(){
    ll n; cin >> n;
    ll x; cin >> x;
    ll noOfAs = round(sqrt(2*x)) - 1;
    // cout << noOfAs << "\n";
    ll rem = n-2 - noOfAs;
    // cout << rem << "\n";
    ll orderNo = noOfAs * (noOfAs + 1) / 2;
    // cout << orderNo << "\n";
    ll z = x - orderNo - 1;
    // cout << z << "\n";
    string t;
    loop(i, 0, rem){
        t = t + "a";
    }
    t += "b";
    loop(i, 0, noOfAs - z){
        t = t + "a";
    }
    t = t + "b";
    loop(i, 0, z){
        t = t + "a";
    }
    cout << t << "\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}