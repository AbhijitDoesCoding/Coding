#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll x, y;
    cin>>x>>y;
    if(x == 0 && y == 0){
        cout<<0<<endl; return;
    }
    // if(x % 7 != 0){
    //     ll k = x% 7;
    //     x += (7 - k);
    // }
    ll z = y / 2;
    
    ll zl = y % 2;
    if(x <= 7 && y >= 1){
        cout<<z + zl<<endl;   return;
    }
    if(y == 0 && x <= 15){
        cout<<1<<endl; return;
    }
    if(y <= 2 && x <= 7){
        cout<<1<<endl; return;
    }

    ll squares = x + (y*4);
    // cout<<x<<" "<<y<<" "<<squares<<endl;
    ll uzi = squares / 15;
    if(squares % 15 != 0)uzi++;
    ll count = z + zl;
    ll mpl = max(count , uzi);
    cout<<mpl<<endl; 
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}