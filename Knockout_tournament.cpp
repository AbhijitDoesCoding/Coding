#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i, l, h) for(int i = l; i < h; i++)
#define rev(i, l, h) for(int i = h - 1; i >= l; i--)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

// Function to calculate the maximum number of matches a player can win
ll num(ll n) {
    if (n == 1) return 0;
    return 1 + num(n / 2);
}

void solve() {
    ll n = 16;
    vi a(n);
    loop(i, 0, n) cin >> a[i];
    
    vi b = a;
    vi c(n, 0);
    sort(all(b));
    
    // Map the skill levels to the number of matches they can win
    loop(i, 0, n) {
        c[b[i]] = num(i + 1);
    }
    
    // Output the results for the original skill levels
    loop(i, 0, n) {
        cout << c[a[i]] << " ";
    }
    nline;
}

int main() {
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
