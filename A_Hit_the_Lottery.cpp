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
// 1, 5, 10, 20, 100
ll n; cin>>n;
ll hundred = n / 100;
n = n % 100;
ll twenty = n / 20;
n = n % 20;
ll ten = n / 10;
n = n % 10;
ll five = n / 5;
n = n % 5;
ll total = n + five + ten + twenty + hundred;
cout<<total;
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