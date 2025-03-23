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
    ll n, k, pbs, ps;
    cin>>n>>k>>pbs>>ps;
    pbs--; ps--;
    vi perm, arr;
    for(ll i = 0; i < n; i++){
        ll ele; cin>>ele; ele--; perm.pb(ele);
    }
    ll max_term = INT_MIN;
    for(ll i = 0; i < n; i++){
        ll ele; cin>>ele; max_term = max(max_term, ele);
        arr.pb(ele);
    }
    ll kzu = 1, uzu = 1;
    ll maxB = INT_MIN, maxS = INT_MIN;
    ll total = 0, total1 = 0;
    int ii = 0, jj = 0;
    for(ll i = 0; i < k; i++){
        if((kzu == 1 || pbs != perm[pbs]) && ii == 0){    
        ll maxB1 = total + (arr[pbs]*(k - i));
        total += arr[pbs];
        if(arr[pbs] == max_term) ii = 1;
        pbs = perm[pbs];
        maxB = max(maxB, maxB1);
        kzu = 0;
        }
        if((uzu == 1 || ps != perm[ps]) && jj == 0){
        ll maxS1 = total1 + (arr[ps]*(k - i));
        total1 += arr[ps];
        if(arr[ps] == max_term) jj = 1;
        ps = perm[ps];
        maxS = max(maxS, maxS1);
        uzu = 0;
        }
    }
    if(maxB > maxS) cout<<"Bodya"<<endl;
    else if(maxS > maxB) cout<<"Sasha"<<endl;
    else cout<<"Draw"<<endl; 
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