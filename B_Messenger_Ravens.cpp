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
/*B. Messenger Ravens
time limit per test
1 second
memory limit per test
256 megabytes

There's been a constant war is going in between Winterfell and King's Landing in the Game Of Thrones from Season 1 - 7 (Ignore Season 8 for goodness' sake :P).

While on the war, the messenger Ravens are always on the travel. Ravens are always a mysterious creature. The difficulty of the route from City A
to City B

for travelling of Ravens is calculated by using the difficulty values of Ravenoids in between them.

Suppose there are N
Ravenoids R1,…,RN in between City A and City B with difficulty values D1,D2,…,DN respectively. The difficulty of the route from A to B is calculated as D1⊕D2⊕⋯⊕DN, where ⊕

denotes the Bitwise Xor.

Maester Luwin already knew this. While studying he's wondering how we can efficiently calculate the total difficulty T
of the total route if the Raven travels M times on the same route. For M=2 the Raven travels from A to B then B to A. For M=3, the Raven first travels from A to B, then back from B to A, and then from A to B. In the other words, the total difficulty T

is given as
T=(D1⊕D2⊕⋯⊕DN)⊕…⊕(D1⊕D2⊕⋯⊕DN)N×M numbers

Since total difficulty T
can be too large, Maester Luwin is interested in its modulo value taken with 109+7

. Please help him to find that.
Input

The first line contains two integers M
and N - the number of times the Raven travel on the same path from A to B, and the number of Ravenoids in between two cities A and B respectively (1≤M≤1018, 1≤N≤106

).

The next line contains the difficulty of the Ravenoids D
, 1≤Di<244

.
Output

Print a single line containing the total difficulty T
modulo 109+7

.
Examples
Input
Copy

3 4
2 4 5 11

Output
Copy

8

Input
Copy

2 3
14 2 3

Output
Copy

0

Note

Explanation 1
: T=(2⊕4⊕5⊕11)⊕(2⊕4⊕5⊕11)⊕(2⊕4⊕5⊕11)=8

Explanation 2
: T=(14⊕2⊕3)⊕(14⊕2⊕3)=0.*/
typedef vector<ll> vi;
typedef pair<ll,ll> pi;

void solve(){
    // write your code here
    ll m , n;
    cin >> m >> n;
    vi a(n);
    loop(i, 0, n){
        cin >> a[i];
    }
    ll ans = 0;
    loop(i, 0, n){
        ans ^= a[i];
    }
    if (m % 2 == 0) {
        cout << 0;
    } else {
        cout << ans % mod;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}