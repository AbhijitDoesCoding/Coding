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
    // Your code here
    ll x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(y1 == y2 && x2 == x3){
        cout<<"NO\n";
        return;
    }
    if(y2 == y3 && x3 == x1){
        cout<<"NO\n";
        return;
    }
    if(y3 == y1 && x1 == x2){
        cout<<"NO\n";
        return;
    }
    if(x1 == x2 && y2 == y3){
        cout<<"NO\n";
        return;
    }
    if(x2 == x3 && y1 == y3){
        cout<<"NO\n";
        return;
    }
    if(x3 == x1 && y2 == y1){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}