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
    ll n, k;
    cin>>n>>k;
    set<ll> s;
    vi v(n);
    map<ll,ll> m;
    ll ele;
    loop(i,0,n) cin>>ele, v[i] = ele, s.insert(ele), m[ele]++;
    ll size = s.size();
    if(size == n || k >= n - size){
        ll ans = (n)*(n-1)/2;
        cout<<ans;
        nline;
        return;
    }
    for(auto &i : m){
        if(k == 0) break;
        if(i.ss > 1){
            if(i.ss - 1 > k){
                i.ss -= k;
                k = 0;
            }
            else{
                k -= i.ss - 1;
                i.ss = 1;
            }
        } 
    }
        // for(auto i : m){
        //     cout<<i.ff<<" "<<i.ss;
        //     nline;
        // }
        ll ans = 0;
        for(auto i : v){
            n--;
            if(m[i] == 1){
            ans +=n;
            }
            else{
               ans += max((n - m[i] - 1), (ll)0); 
            }

        }
        cout<<ans;
        nline;
        return;
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