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
    int a,b,c;
    cin>>a>>b>>c;
    int i = 0;
    for(int i = 0; i < ((c+1)*a)+1; i++){
        for(int j = 0; j < ((c+1)*b)+1; j++){
            if(i%(c+1) == 0 || j %(c+1) == 0) cout<<"*";
            else if(i%(2*(c+1)) == j %(2*(c+1))) cout<<"\\";
            else if(i%(2*(c+1))+j %(2*(c+1))== 2*(c+1)) cout<<"/";
            else cout<<".";
        }
        cout<<endl;
    }
    cout<<endl;
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