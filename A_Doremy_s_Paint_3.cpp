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
    ll n; cin>>n; vi kzi(100000, 0);
    set<ll> uzi;
    for(ll i = 0; i < n; i++){
        ll ele; cin>>ele;
        uzi.insert(ele);
        kzi[ele]++;
    }
    if(uzi.size()>2) {
        no return;
    }
    if(uzi.size() == 1){
        yes return;
    }
    ll total;
    auto it = uzi.begin(); // Iterator pointing to the first element
    ll ele1 = *it; // Accessing the first element
    ++it; // Move iterator to the next element
    ll ele2 = *it; // Accessing the second element
    total = abs(kzi[ele1] - kzi[ele2]); 
    
    if(total == 1 || total == 0) {
        yes return;

    }
    no
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