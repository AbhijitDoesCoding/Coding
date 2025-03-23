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
int n;
cin>>n;
int mini = INT_MAX;
int count = 0;
vector<int> uzi;
for(int i = 0; i < n; i++){
    int ele;
    cin>>ele;
    // if(mini > ele){
    // mini = min(mini, ele);
    // count = 0;
    // }
    // if(mini == ele){
    //     count++;
    // }
    uzi.pb(ele);
}
// if(mini == 1 && count > 1){
//     cout<<"NO"<<endl; return;
// }
// else if(mini == 1 && count == 1){
//     cout<<"YES"<<endl; return;
// }

sort(uzi.begin(), uzi.end());
if(uzi[0] != uzi[1]){
    cout<<"YES"<<endl; return;
}
for(int i = 0; i < n ; i++){
    // int zz = uzi[i + count] % mini;
    if(uzi[i] % uzi[0] != 0){
        cout<<"YES"<<endl; return;
    }
}
cout<<"NO"<<endl; return;
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