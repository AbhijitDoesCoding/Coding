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
vector<int> uzi;
int count =0;
loop(i, 0, n){
    int ele;
    cin>>ele;
    // if(ele == 0 && i != n-1) count++;
    uzi.pb(ele);
}
// if(count != 0){cout<<"-1"<<endl; return;}
int k = 0;
if(uzi.size() == 1){cout<<"0"<<endl; return;}
rev(i, 1, n){
    while(uzi[i]<=uzi[i-1] && uzi[i-1] != 0){
        uzi[i-1]/= 2;
        k++;
    }
    if(uzi[i-1]==0 && i > 1){
        k = -1; break;
    }
    if(uzi[1] == 0){
        k = -1; break;
    }   
}
cout<<k<<endl;
// for(auto k: uzi){
//     cout<<k<<" ";
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