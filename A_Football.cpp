#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
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
    string s; cin>>s;
    int lonchain = 1;
    int currchain = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == s[i]){
            currchain++;
            lonchain = max(lonchain, currchain);
        }
        else{
            currchain = 1;
        }
    }
    if(lonchain >= 7) yes
    else no
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