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

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        // if b is odd
        if(b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1; // b = b/2
    }
    return res;
}

void solve(){
    // write your code here
    //2^20 + 11^7 + 4^40 + 3^30 + 5 ^50
    // modulus all this 7
    ll sum = 0;
    sum += binpow(2,20,7);
    sum %= 7;
    sum += binpow(11,7,7);
    sum %= 7;
    sum += binpow(4,40,7);
    sum %= 7;
    sum += binpow(3,30,7);
    sum %= 7;
    sum += binpow(5,50,7);
    sum %= 7;
    cout<<sum;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}