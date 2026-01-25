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
     int n, a ,b; set<int> uzi;
     cin>>n>>a;
     for(int i = 0; i < a; i++){
        int ele; cin>>ele; uzi.insert(ele);
     }
     cin>>b;
     for(int i = 0; i < b; i++){
        int ele; cin>>ele; uzi.insert(ele);
     }
     if(uzi.size()!= n) cout<<"Oh, my keyboard!"; else cout<<"I become the guy.";
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}