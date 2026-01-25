/*D. Same Differences
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given an array a
of n integers. Count the number of pairs of indices (i,j) such that i<j and aj−ai=j−i

.
Input

The first line contains one integer t
(1≤t≤104). Then t

test cases follow.

The first line of each test case contains one integer n
(1≤n≤2⋅105

).

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤n) — array a

.

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case output the number of pairs of indices (i,j)
such that i<j and aj−ai=j−i

.
Example
Input
Copy

4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6

Output
Copy

1
3
3
10
*/

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
    ll n;
    cin>>n;
    vi a(n);
    loop(i,0,n) cin>>a[i];
    ll count = 0;
    map<ll,ll> k;
    loop(i,0,n){
        k[a[i] - i - 1]++;
    }

    for(auto i:k){
        count += (i.ss*(i.ss-1))/2;
    }
    cout<<count; nline

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