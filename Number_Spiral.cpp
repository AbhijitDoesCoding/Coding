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

void solve(){
    // write your code here
    ll x, y;
    cin >> x >> y;
    if(y > x){
        if(y & 1){
           cout << y*y - x + 1;
           return; 
        }
        else{
            cout << (y-1)*(y-1) + x;
            return;
        }
    }
    else{
        if(x & 1){
            cout << (x-1)*(x-1) + y;
            return;
        }
        else{
            cout << x * x - y + 1;
            return;
        }
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
        nline;
    }
    return 0;
}