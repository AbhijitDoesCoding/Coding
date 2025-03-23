#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define nline cout<<"\n";
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
    vi ans(32);
    ll rem = 0;
    while(n > 0){
        if(n % 2 == 0)
        ans[rem] = 0;
        else
        ans[rem] = 1;
        n /= 2;
        rem++;
        // cout<<n;
        // nline
    }
    // loop(i)
    // cout<<ans.size();
    // nline 
    // loop(i,0,ans.size())
    // cout<<ans[i]<<" ";
    // nline;
    ll minus = 0;
    cout<<"32"; nline;
    loop(i, 0, 32){
        if(ans[i] == 1 && minus == 0 && ans[i - 1] == 1){
            cout<<"-1"<<" ";
            minus = 1;   
        }
        else if(ans[i] == 1 && minus == 0 && ans[i - 1] == 0){
            cout<<"1"<<" ";
        } 
        else if(ans[i] == 1 && minus == 1){
            cout<<"0"<<" ";
        }
        else if(ans[i] == 0 && minus == 1 && ans[i - 1] == 0){
            cout<<"1"<<" ";
            minus = 0;
        }
        else if(ans[i] == 0 && minus == 1){
            cout<<"-1"<<" ";
        }
        else if(ans[i] == 0 && minus == 0){
            cout<<"0"<<" ";
        }
    }
    nline;
// printBinary(n);
// cout<<"\n";
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