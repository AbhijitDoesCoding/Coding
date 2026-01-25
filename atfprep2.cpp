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

ll convert_to_integer(char s){
    return s - '0';
}

void solve(){
    // Your code here
    string n;
    cin>>n;
    vi a;
    if(n[0] != '9'){
        ll u = convert_to_integer(n[0]);
        u = min(u, 9-u);
        a.pb(u);
    }
    else{
        a.pb(9);
    }
    loop(i, 1, n.size()){
        ll u = convert_to_integer(n[i]);
        u = min(u, 9-u);
        a.pb(u);
    }
    for(auto x: a){
        cout<<x;
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