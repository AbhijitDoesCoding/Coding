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
//     Bouncing Ball

// You are given an array AA of length NN, where each element represents either empty ground (Ai=0Ai​=0) or a wall (a positive integer indicating the height of the wall).

// You can place a ball on any empty ground (that is, choose an index ii with Ai=0Ai​=0) and push it either to the right or to the left.
// When the ball hits a wall, it decreases the height of the wall it hit by 11, and then bounces back in the opposite direction. If the wall's height reaches 00, it becomes empty ground.
// The ball continues to move until it goes out of bounds.

// Determine the number of ways to place and push the ball so that all walls are destroyed. Two ways are considered different if either the starting index of the ball or the direction of the push is different.
// Input Format

//     The first line contains a single integer TT, denoting the number of test cases.
//     Each test case consists of two lines of input.
//         The first line of each test case contains a single integer NN, denoting the size of the array AA.
//         The second line of each test case contains NN space-separated integers A1,A2,…,ANA1​,A2​,…,AN​.
//         Ai=0Ai​=0 means the ii-th position is empty ground, and Ai>0Ai​>0 denotes a wall of height AiAi​ at position ii.

// Output Format

// For each test case, print on a new line a single integer representing the number of ways all walls can be destroyed.
    ll n;
    cin>>n;
    vi a(n);
    vi sum(n, 0);
    loop(i, 0, n) {cin>>a[i];}
    sum[0] = a[0];
    loop(i, 1, n) {
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    loop(i, 0, n) {
        if(a[i] == 0) {
            ll diff = sum[n-1] - sum[i];
            if(diff == sum[i]) {
                ans += 2;
            }
            else if(abs(diff - sum[i]) == 1) {
                ans++;
            }
        }
    }
    cout<<ans;
    nline;
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