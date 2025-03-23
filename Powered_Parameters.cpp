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
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
void solve(){
    ll n; cin>>n; 
    vector<ll> uzi;
    ll count = 0;
    // vector<double> kzi;
    for(ll i = 0; i < n; i++){
        ll ele; cin>>ele; uzi.pb(ele);
        // kzi.pb(double(pow(ele, 1.0/(i+1))));
        // cout<<kzi[i]<<" ";
    }
    // cout<<endl;
    // sort(all(kzi));
    // for(ll i = 0; i < n; i++){
    //     cout<<kzi[i]<<" ";
    // }
    // // cout<<endl;
    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < n; j++){
    //         if(uzi[i]<= kzi[n-j-1]){
    //             count++;
    //             // cout<<uzi[i]<<" "<<kzi[i]<<" "<<i<<endl;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // count--;
    // ll j = 0;
    // for(ll i = 0; i < n; i++){
    //     ll low = 0; ll high =  n-1;
    //     ll mid;
    //     while(low <= high){
    //         mid = (low + high )/2;
    //         if(uzi[i]<= kzi[mid]){
    //             high = mid-1;

    //         } 
    //         else{
    //             low = mid+1;
    //         }
    //     }
    //     count+= mid - high;
    //     // j++;
    // }
     for(ll i = 0; i < n; i++){
        ll l = uzi[i];
        if(l == 1) 
            count += n;
        else{
            ll p = 1;
            for(ll j = 0; j < n; j++){
                p *= l;
                if(p > mod-7) 
                    break;
                else{
                    ll r = uzi[j];
                    if(p <= r) 
                        count++;
                }
            }
        }
    }
    cout<<count<<endl;
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