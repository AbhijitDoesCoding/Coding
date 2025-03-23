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
/*A. Shape Perimeter
time limit per test
1 second
memory limit per test
256 megabytes

There is an m
by m square stamp on an infinite piece of paper. Initially, the bottom-left corner of the square stamp is aligned with the bottom-left corner of the paper. You are given two integer sequences x and y, each of length n. For each step i from 1 to n

, the following happens:

    Move the stamp xi

units to the right and yi
units upwards.
Press the stamp onto the paper, leaving an m
by m

    colored square at its current position. 

Note that the elements of sequences x
and y have a special constraint: 1≤xi,yi≤m−1

.

Note that you do not press the stamp at the bottom-left corner of the paper. Refer to the notes section for better understanding.

It can be proven that after all the operations, the colored shape on the paper formed by the stamp is a single connected region. Find the perimeter of this colored shape.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤1000

). The description of the test cases follows.

The first line of each test case contains two integers n
and m (1≤n≤100, 2≤m≤100

) — the number of operations performed and the side length of the square stamp.

The i
-th of the next n lines contains two integers xi and yi (1≤xi,yi≤m−1) — the distance that the stamp will be moved right and up during the i

-th operation, respectively.

Note that there are no constraints on the sum of n

over all test cases.
Output

For each test case, output a single integer representing the perimeter of the colored shape on the paper.*/
void solve(){
    // Your code here
    ll n, m;
    cin>>n>>m;
    ll perimeter = 4 * m;
    ll bn, mn;
    cin>>bn>>mn;
    loop(i, 0, n-1){
        ll x, y;
        cin>>x>>y;
        perimeter += 2 * m;
        perimeter -= ((m-x)+(m-y));
        perimeter += x+y;
    }
    cout<<perimeter<<"\n";
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