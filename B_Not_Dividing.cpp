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
int n; cin>>n;
vector<int> uzi;

loop(i , 0, n){
    int ele;
    cin>>ele;
    ele++;
    uzi.pb(ele);
}
loop(i, 1, n){
    if(uzi[i] % uzi[i-1]==0){
        uzi[i]++;
    }
}


// rev(i, 1, n){
//     if(i == n-1){
//    if(uzi[i-1] == 1){
//             uzi[i-1]++;
//         }
//         if(uzi[i]% uzi[i-1]==0){
//             uzi[i]++;
//         }
//     } 
//     else{
//         if(uzi[i-1] == 1){
//         uzi[i-1]++;
//         }
//         if(uzi[i]% uzi[i-1] == 0){
//             uzi[i]++;
//             if(uzi[i+1]% uzi[i]==0){
//                 uzi[i+1]++;
//             }
//         }
//         }
// }

loop(i , 0, n){
    cout<<uzi[i]<<" ";
    }
    cout<<endl;
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