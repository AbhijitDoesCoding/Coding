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
#define mod 1000000007...
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
void solve(){
    string s; cin>>s;
    ll n = s.size();
    ll ones = 0;
    ll total = 0;
    // for(int i = 0; i < n; i++){
    //     if(s[i] == '1') ones++;
    // }
    // for(int i = n-1; i >= 0; i--){
    //     if(s[i] == '0'){
    //         if(ones > 0)
    //         total += (ones+1);
    //     }
    //     if(s[i] == '1'){
    //         ones--;
    //         if(ones == 0) break;
    //     }
    // }
    ll curr = 0; 
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == '1'){
            ones++;
        }
        else{
            if(ones>0){
                total += ones + 1;
            }
        }
    }
    cout<<total<<endl;
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