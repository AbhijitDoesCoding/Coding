#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
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

vi prefix_sum(vi a){
    vi prefix(a.size());
    prefix[0] = a[0];
    loop(i,1,a.size()){
        prefix[i] = prefix[i-1] + a[i];
    }
    return prefix;
}

void solve(){
    // Your code here
    ll n;
    cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    ll sum = accumulate(all(a),0);
    vi prefix = prefix_sum(a);
    vi ans(sum+1);
    // loop(i, 0, prefix.size()){
    //     cout<<prefix[i]<<" ";
    // }
    // nline;
    loop(i,0,n){
        loop(j,prefix[i]-a[i]+1,prefix[i]+1){
            ans[j] = i+1;
        }
    }
    nline;
    ll m;
    cin>>m;
    vi b(m);
    loop(i,0,m) cin>>b[i];
    loop(i,0,m){
        cout<<ans[b[i]]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}