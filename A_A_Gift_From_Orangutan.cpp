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
    ll n;
    cin>>n;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    sort(all(v));
    ll mini = 1, maxi = 1;
    mini = v[0];
    maxi = v[n-1];
    ll ans = 0;
    maxi *= (n);
    
    mini *= (n-1);
    mini += v[n-1];
    // cout<<maxi<<" "<<mini; nline;      
    ans = maxi-mini;
    // cout<<ans; nline;
    ll ans1 = 0;
    ll mini1 = 1, maxi1 = 1;
    mini1 = v[0];
    maxi1 = v[n-1];
    mini1 *= (n);
    maxi1 *= (n-1);
    mini1 += v[0];
    // cout<<maxi1<<" "<<mini1; nline;
    ans1 = maxi1-mini1;
    cout<<max(ans,ans1); nline;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}