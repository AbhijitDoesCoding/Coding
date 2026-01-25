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

ll find_streak_value(vi &v){
    ll n = v.size();
    ll streak = 0;
    ll prev = -inf;
    ll ans = 0;
    loop(i, 0, n){
        if(v[i] >= prev){
            streak++;
        }
        else{
            ans = max(ans, streak);
            streak = 1;
        }
        prev = v[i];
    }
    ans = max(ans, streak);
    return ans;
}

void solve(){
    ll n; cin >> n; 
    ll x; cin >> x;
    vi v(n);
    loop(i, 0, n){
        cin >> v[i];
    }
    ll ans = find_streak_value(v);
    loop(i, 0, n){
        v[i] *= x;
        ans = max(ans, find_streak_value(v));
        v[i] /= x;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}