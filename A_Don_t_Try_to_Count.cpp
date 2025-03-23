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
    ll m, n;
    cin>>n>>m;
    string s, x;
    cin>>x>>s;
    // ll count = 0;
    for(ll i = 0; i < 6; i++){
        if(x.find(s) != string::npos){
            cout<<i<<endl;
            return;
        }
        x+=x;
    }
    cout<<"-1"<<endl;
    // while(x.size() <= 10000){
    //     x = x + x;
    // }
    // // cout<<x<<endl;
    // ll j = 0;
    // ll lastcnt = -1; 
    // for(ll i = 0; i < 25; i++){
    //     if(x[i] == s[j]){
    //         j++;
    //         if(j == m){
    //             lastcnt = i;
    //             break;
    //         }
    //     }
    //     else{
    //         j = 0;
    //         if(x[i] == s[j]){
    //             j++;
    //             if(j == m){
    //             lastcnt = i;
    //             break;
    //         }
    //         }
    //     }
    // }
    // // cout<<lastcnt<<endl;
    // ll count = 0;
    // while(lastcnt+1>n){
    //     n *= 2;
    //     count++;
    // }
    // // cout<<lastcnt<<endl;
    // if(lastcnt == -1){
    //     cout<<lastcnt<<endl;
    // }
    // else
    // cout<<count<<endl;
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
