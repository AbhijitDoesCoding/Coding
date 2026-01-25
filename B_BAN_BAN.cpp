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
    ll n;
    cin>>n;
    if(n==1){
        cout<<1;
        nline;
        cout<<1<<" "<<2;
        nline;
        return;
    }
    if(n % 2 == 0){
        cout<<n/2;
        nline;
        ll i = 1, j = 5;
        for(ll k = 0; k < n/2; k++){
            cout<<i<<" "<<j;
            nline;
            i += 6;
            j += 6;
        }
    }
    else{
        cout<<(n+1)/2;
        nline;
        cout<<1<<" "<<2;
        nline;
        ll i = 4, j = 8;
        for(ll k = 0; k < (n+1)/2 - 1; k++){
            cout<<i<<" "<<j;
            nline;
            i += 6;
            j += 6;
        }

    }
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