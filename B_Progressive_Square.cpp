#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
void solve(){
int n, a, b;
cin>>n>>a>>b;
vector<ll> uzi;
for(int i = 0; i < n*n; i++){
    ll ele;
    cin>>ele;
    uzi.pb(ele);
}
sort(uzi.begin(), uzi.end());
ll z = uzi[0];
ll k = 0; vector<ll> uzi1;
for(int i = 0; i < n; i++){
uzi[0] = z + (i * b);
for(int j = 0; j < n; j++){
k = uzi[0]+(j*a);
uzi1.pb(k);
}
}
uzi[0] = z;
sort(uzi1.begin(), uzi1.end());
if(uzi1 == uzi){
    yes;
}
else no;
// for(int i = 0; i < n*n;  i++){
//     cout<<uzi[i]<<" ";
// }
// cout<<endl;
// for(int i = 0; i < n*n;  i++){
//     cout<<uzi1[i]<<" ";
// }
// cout<<endl;
}
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}
