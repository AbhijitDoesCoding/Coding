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
int total = 0;
int count = 0;
for(int i = 0; i < n; i++){
    int ele;
    cin>>ele;
    total += ele;
    if(ele % 3 == 1){
        count++;
    }
}
if(total % 3 == 0){
    cout<<0<<endl;
return;
}
else if(total % 3 == 1 && count > 0){
    cout<<1<<endl;
    return;
}
else if(total % 3 == 1){
    cout<<2<<endl;
    return;
}
else{
    cout<<1<<endl;
    return;
}
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