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
    ll n; cin>>n;
    string s;
    cin>>s;
    ll left = 0;
    ll right = n-1;
    while(right >= left){
        if(s[left] == '1' && s[right] == '0'){
            left++; right--;
        }
        else if(s[left] == '0' && s[right] == '1'){
            left++; right--;
        }
        else{
            break;
        }
    }
    ll ans = right - left + 1;
    if(left > right){
        cout<<0; nline;
    }
    else{
        cout<<ans; nline;
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