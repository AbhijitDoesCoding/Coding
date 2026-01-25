#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES\n";
#define no cout << "NO\n";
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

void solve() {
    string s, t, d;
    cin >> s >> t >> d;
    // cout<<s<<t<<d;
    ll arr[26] = {0}; // Initialize the array to zero

    for (auto z: s) {
        arr[z - 'A']++;
    }
    for (auto z: t) {
        arr[z - 'A']++;
    }
    for (auto z: d) {
        arr[z - 'A']--;
    }

    for (auto z: arr) {
        if (z != 0) {
            no
            return;
        }
    }
    yes
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
