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
//     Permutation Construction

// You are given an integer NN.
// Find a permutation†† PP of the integers 11 to NN such that
// Pi≥(Pi+1−Pi−1)2
// Pi​≥(Pi+1​−Pi−1​)2

// holds for every index ii from 22 to N−1N−1.

// It can be proved that at least one solution exists.
// If multiple solutions exist, print any of them.

// †† A permutation of the integers 11 to NN is an array of length NN that contains every integer from 11 to NN.
// Input Format

//     The first line of input will contain a single integer TT, denoting the number of test cases.
//     The first and only line of each test case contains a single integer NN.

// Output Format

// For each test case, output on a new line NN space-separated integers — the permutation PP for which the above condition holds.

// If multiple solutions exist, you may print any of them.
    ll n;
    cin>>n;
    if(n % 2 == 0) {
        ll q = n / 2 + 1;
        ll p = 1;
        loop(i, 0, n){
            if(i % 2 == 0){
                cout<<p<<" ";
                p++;
            }
            else{
                cout<<q<<" ";
                q++;
            }
        }
    }
    else{
        ll q = n / 2 + 2;
        ll p = 1;
        loop(i, 0, n){
            if(i % 2 == 0){
                cout<<p<<" ";
                p++;
            }
            else{
                cout<<q<<" ";
                q++;
            }
        }
    }
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