#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
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
    // Your code here
    ll n, k;
    cin>>n>>k;
    string s, t;
    cin>>s>>t;
    ll zeros = 0, ones = 0;
    ll total_zeros = 0, total_ones = 0;
    loop(i,0,n){
        if(s[i]!=t[i]){
            if(s[i]=='0') zeros++;
            else ones++;
        }
        if(s[i]=='0') total_zeros++;
        else total_ones++;
    }
    if(zeros != ones){
        cout<<"No\n";
        return;
    }
    if(zeros <= k){
        if(total_ones >= 2 || total_zeros >= 2){
            cout<<"Yes\n";
            return;
        }
        else{
            cout<<"No\n";
            return;
        }
    }
    if(zeros % k == 0){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        // cout<<"Case #"<<t<<": ";
        solve();
        // cout<<"\n";
    }
    return 0;
}