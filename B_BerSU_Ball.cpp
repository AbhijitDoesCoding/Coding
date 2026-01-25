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
    ll n,m;
    cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    cin>>m;
    vi b(m);
    loop(i,0,m) cin>>b[i];
    sort(all(a));
    sort(all(b));
    // 2 pointer method
    ll i=0,j=0;
    ll count=0;
    while(i<n and j<m){
        if(abs(a[i]-b[j])<=1){
            count++;
            i++;
            j++;
        }else if(a[i]>b[j]){
            j++;
        }else{
            i++;
        }
    }
    cout<<count;
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