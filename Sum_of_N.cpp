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
vector<ll> primes;
vi allx(1000002, 0);
vector<ll> generatePrimes(ll limit) {
    vector<ll> primes;
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    for (ll p = 2; p <= limit; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
            allx[p] = 1;
            for (ll multiple = p * 2; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    return primes;
}

void solve(){
    ll n;
    cin>>n;
    ll ans = 0;
    if(allx[n] == 1){
        for(auto i: primes){
            if(i > n){
                break;
            }
            ans += n*i; 
        }
    }
    else{
        ll smf = 0;
        for(auto i: primes){
            if(i > n) break;
            if(n%i == 0){
                smf = i;
                break;
            }    
        }
        for(auto i: primes){
            if(i > smf)
            break;
            ans += n*i;
        }
    }
    cout<<ans<<endl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    primes = generatePrimes(1000001);
    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}