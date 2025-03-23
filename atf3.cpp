/*You are an ATF student visiting a tree with N levels. Each level of the tree has a unique treehouse. You are given n starting levels x1,x2,…,xn. If you start from level xi, you can only visit levels that are multiples of xi

.

Determine the total number of distinct levels you can visit across all starting levels.

Input

The first line contains two integers n
and N (1≤n≤2×105,1≤N≤2×105)

— the number of starting levels and the number of levels in the tree, respectively.

The second line contains n
integers x1,x2,…,xn (1≤xi≤N)

— the starting levels.

Output

Output a single integer — the total number of distinct levels you can visit across all starting levels.*/

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

void solve() {
    ll n, N;
    cin >> n >> N;
    vector<bool> visited(N + 1, false);
    unordered_set<ll> unique_x;
    ll count = 0;

    loop(i, 0, n) {
        ll x; cin >> x;
        if (unique_x.find(x) == unique_x.end()) {
            unique_x.insert(x);
            for (ll j = x; j <= N; j += x) {
                if (!visited[j]) {
                    visited[j] = true;
                    count++;
                }
            }
        }
    }
    cout << count;
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