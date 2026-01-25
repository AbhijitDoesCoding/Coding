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
     ll n, k;
     cin>>n>>k;
     vector<ll> uzi;
     ll total = 0; 
     for(ll i = 0 ; i < n ; i++){
        ll ele; cin>>ele; uzi.pb(ele);
        total += ele;
     }
     vector<pair<ll,ll>>subpairs;
     for(ll i = 0; i < n-1; i++){
        // ll m;
        // if(uzi[i] > uzi[i+1]) m = i;
        // else m = i+1;
        subpairs.pb({abs(uzi[i] - uzi[i+1]), i});
    }
    // sort(all(subpairs));
    // // int u = subpairs.size();
    // for(int i = 0; i < k; i++){
    //     total -= subpairs[n-2].first;
    //     subpairs[n-2].first == 0;
    //     ll ut = subpairs[n-2].second;
    //     if(uzi[ut] > uzi[ut+1]){
    //         uzi[ut] = uzi[ut+1];
    //         if(ut != 0){
    //             ll z = abs(uzi[ut-1] - uzi[ut]);
    //             for(ll j = 0; j < n-1; j++){
    //                 if(subpairs[j].second == ut-1){
    //                     subpairs[j].first = z;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     else if(uzi[ut] < uzi[ut+1]){
    //         uzi[ut+1] = uzi[ut]; 
    //         if(ut+1 != n-1){
    //             ll z = abs(uzi[ut+1] - uzi[ut+2]);
    //             for(ll j = 0; j < n-1; j++){
    //                 if(subpairs[j].second == ut + 1){
    //                     subpairs[j].first = z;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // sort(all(subpairs));
    // }
    cout<<total<<endl;
}
void solve1(){
    ll n, a, b;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--){
        solve1();
    }
    return 0;
}