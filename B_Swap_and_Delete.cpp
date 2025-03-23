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
    ll n;
    string s; cin>>s;
    n = s.size();
    ll ones = 0, zeros = 0;
    loop(i, 0, n){
        if(s[i] == '1'){
            ones++;
        }
        else{
            zeros++;
        }
    }
    if(ones == 0 || zeros == 0){
        cout<<n;nline; return;
    }
    else if(zeros == ones){
        cout<<0; nline; return;
    }
    else{
        // cout<<2*min(zeros, ones);
        loop(i, 0, n){
            if(s[i] == '1'){
                if(zeros == 0){
                    cout<<ones; nline return;
                }
                zeros--;
                
            }
            else{
                if(ones == 0){
                    cout<<zeros; nline return;
                }
                ones--;
            }
        }
        nline; return;
    }
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