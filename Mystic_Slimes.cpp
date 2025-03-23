#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define loop(i,l,h) for(int i=l;i<h;i++)
#define mod 1000000007

void solve() {
    ll n; 
    cin >> n;
    vector<ll> a(n);
    
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ans = a; 
    
    if (n == 2) {
        ans[0] = max(0LL, a[0] - a[1]);
        ans[1] = max(0LL, a[1] - a[0]);
    } 
    else if (n == 3) {
        ans[1] = max(0LL, a[1] - (a[0] + a[2]));
    } 
    else { 
        ans[1] = max(0LL, a[1] - a[0]);      
        ans[n-2] = max(0LL, a[n-2] - a[n-1]); 
    }

    ll maxi = *max_element(ans.begin(), ans.end());
    cout << maxi << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
