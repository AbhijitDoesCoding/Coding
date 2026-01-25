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
    unordered_map<ll , ll> uzi;
    ll n;
    cin>>n;
    ll greater = 0;
    loop(i,0,n){
        ll x;
        cin>>x;
        ll z = ++uzi[x];

        if(z > greater){
            greater = z;
        }
    }
        if(greater == n){
            cout<<0; nline; return;
        }
        // ll needed = n - greater;
        // cout<<needed<<" "<<greater<<" ";
        // ll count = 0;
        ll ans = 0;
        while(greater < n){
            ll d = min(n - greater, greater);
            ans += 1+d;
            greater += greater;
            // count++;
        }
        cout<<ans; nline;
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