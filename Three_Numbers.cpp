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
    ll k, s;
    cin >> k >> s;
    ll ans = 0;
    // to ensure s-z is below 2*k
    ll st = max(0, s - 2 * k);
    // to ensure s-z is greater than equal to 0
    ll end = min(k, s);
    for (int z = st; z <= end; z++) // loop for all possible values of x
    {
        ll rem = s - z;
        if (rem > k)
            ans += (2 * k - rem + 1);
        else
            ans += (rem + 1);
    }
    cout << ans << "\n";

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