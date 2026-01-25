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
    ll n, k, x;
    cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    cin>>k>>x;

    // Sorting the array
    sort(all(a));

    // Binary search for the position of x or the nearest element
    auto pos = lower_bound(all(a), x) - a.begin();
    ll l = pos - 1, r = pos;
    cout<<pos<<" "<<l<<" "<<r<<"\n";
    vi ans;
    // Finding the k closest elements
    while(k--){
        if(l < 0){ // If left pointer goes out of bounds
            ans.pb(a[r]);
            r++;
        }
        else if(r >= n){ // If right pointer goes out of bounds
            ans.pb(a[l]);
            l--;
        }
        else if(abs(a[l] - x) <= abs(a[r] - x)){ // Compare and add the closer element
            ans.pb(a[l]);
            l--;
        }
        else{
            ans.pb(a[r]);
            r++;
        }
    }

    // Sorting the answer and printing it
    sort(all(ans));
    for(auto i: ans){
        cout<<i<<" ";
    }
    nline;
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
