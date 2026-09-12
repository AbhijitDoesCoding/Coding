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
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#define mod 1000000007
#define inf 1e18

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

ll binpow(ll b, ll p) {
    ll a = 1;
    for (b %= mod; p; p >>= 1, b = b * b % mod)
        if (p & 1) a = a * b % mod;
    return a;
}

ll modinv(ll a) {
    return binpow(a, mod - 2);
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

void solve() {
    int n;
    string s,t; 
    cin >> n >> s >> t;
    vector<int> aOdd, aEven, bOdd, bEven;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(i%2) aOdd.pb(i);
            else aEven.pb(i);
        }
        if(t[i] == '1'){
            if(i%2) bOdd.pb(i);
            else bEven.pb(i);
        }
    }

    if(aOdd.size() != bOdd.size() || aEven.size() != bEven.size()){
        cout << "NO"<< "\n";
        return;
    }
    else{
        cout << "YES"<< "\n";
        return;
    }

    ll ans = 0;
    for(int i = 0; i < aOdd.size(); i++){
        if(aOdd[i] != bOdd[i]){
            ans+= abs(aOdd[i]-bOdd[i]);
        }
    }
    for(int i = 0; i < aEven.size(); i++){
        if(aEven[i] != bEven[i]){
            ans+= abs(aEven[i]-bEven[i]);
        }
    }
    cout << (ans >> 1) << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}