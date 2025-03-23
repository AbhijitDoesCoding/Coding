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

bool isnotprime(ll n){
    if(n==1) return true;
    if(n==2) return false;
    if(n%2==0) return true;
    for(ll i=3;i*i<=n;i+=2){
        if(n%i==0) return true;
    }
    return false;
}
void solve(){
    // Your code here
    ll n; cin>>n;
    vi v(n, 1);
    ll prime = 101;
    vi primefrom100 = {101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
    loop(i, 0, primefrom100.size()){
        prime = primefrom100[i] - n + 1;
        if(isnotprime(prime)){
            break;
        }
    }
    v[n-1] = prime;
    // loop(i, 0, n) cout<<v[i]<<" ";
    // nline;
    // rotate(v.begin(), v.begin()+1, v.end());
    // loop(i, 0, n) cout<<v[i]<<" ";
    // nline;
    // rotate(v.begin(), v.begin()+1, v.end());
    // loop(i, 0, n) cout<<v[i]<<" ";
    // nline;
    loop(i, 0, n){
        loop(j, 0, n){
            cout<<v[j]<<" ";
        }
        rotate(v.begin(), v.begin()+1, v.end());
        nline;
    }
    // nline;
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