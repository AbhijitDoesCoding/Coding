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

vi prefix_sum(vi &v){
    vi prefix(v.size());
    prefix[0] = v[0];
    loop(i,1,v.size()) prefix[i] = prefix[i-1] + v[i];
    return prefix;
}

void solve(){
    // Your code here
    ll n, k;
    cin>>n>>k;
    vi v(n);
    loop(i,0,n) cin>>v[i];
    sort(all(v));
    vi prefix = prefix_sum(v);
    vi ans(k+1);
    loop(i,0,k+1){
        ans[i] = v[i];
    }
    ll j = 0;
    loop(i,0,k){
        cout<<prefix[i]<<" ";
    }
    loop(i, k, n){
        if(j > k){
            ans[j % (k+1)] += v[i-k];
        }
        cout<<prefix[i]-ans[j % (k+1)]<<" ";
        j++;

    }
    
    nline;
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