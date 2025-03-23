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
    ll a, b, c, m;
    cin>>a>>b>>c>>m;
//     //No Winner

// After a series of matches between Alice, Bob, and Cameron, their scores are AA, BB, and CC, respectively.
// Chef plans to organise MM additional matches. In each match, two players compete, and there is exactly one winner.
// The winner of the match receives one point.

// Determine if it is possible for at least two players to end up with the same score after all MM additional matches have been completed.
    ll lowest = min(abs(a-b), min(abs(b-c), abs(c-a)));
    if(lowest<=m){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
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