/*Akash is naughty playboy. But today, he got selected for ATF Camp and he is a super happy soul.

There are exactly N
days left before he will join ATF camp. Coincidently, he also has exactly N girlfriends. So, Akash plans to spend exactly one day with each of his girlfriends. You are jealous knowing about his plans, so to divert yourself, you focus on finding the number of ways Akash can plan his visits to his N

girlfriends.

Example: Let's say Akash has to visit 3 girlfriends: A, B, C on 3 days. There are exactly 6 ways he can plan his trip:

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
    ll ans = 1;
    loop(i, 1, n+1){
        ans *= i;
    }
    cout<<ans;
    nline
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