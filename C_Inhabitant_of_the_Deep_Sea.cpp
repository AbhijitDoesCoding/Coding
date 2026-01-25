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
ll n, k;
cin>>n>>k;
ll total = 0;
vector<ll> uzi(n);
loop(i, 0, n){
    cin>>uzi[i];
    total += uzi[i];
}
if(k >= total){
    cout<<n<<endl; return;
}

ll count = 0;
ll fi = 0, la = n-1;
while(fi<=la){
    if(fi == la){
        if(uzi[fi] > k){
            cout<<n-1<<endl; return;
        }
        else{cout<<n<<endl; return;}
    }
    if(uzi[fi]+uzi[la] < k)
}
}

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}