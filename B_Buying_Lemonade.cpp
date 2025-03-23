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
    ll k;
    cin>>n>>k;
    set<ll> s;
    unordered_map<ll,ll> m;
    loop(i,0,n){
        ll x;
        cin>>x;
        s.insert(x);
        m[x]++;
    }
    ll final = 0;
    ll count= 0;
    for(auto i = s.begin(); i != s.end(); i++){
        
        ll ans = (*i-final) * (n);
        cout<<"ans = "<<ans; nline;
        if(ans < k){
            k -= ans;
            cout<<"k = "<<k; nline;
            count += n + m[final];
            cout<<"count = "<<count; nline;
            final = *i;
            cout<<"final = "<<final; nline;
            n -= m[*i];
            cout<<"n = "<<n; nline;
        }
        else{
            count += k + m[final];
            cout<<"count = "<<count; nline;
            cout<<count; nline;
            return;
        }
    }
    nline; nline;
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