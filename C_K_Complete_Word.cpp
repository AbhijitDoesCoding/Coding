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

bool isPalindrome(string s){
    ll n = s.size();
    loop(i, 0, n/2){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}
void solve(){
    // Your code here
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    loop(i, 0, k){
        ll grup = 0;
        unordered_map<char, ll> mp;
        for(ll j = i; j < n; j += k){
            mp[s[j]]++;
            grup++;
        }
        for(ll j = k - 1 - i; j < n; j += k){
            mp[s[j]]++;
            grup++;
        }
        ll max1 = 0;
        for(auto x: mp){
            max1 = max(max1, x.second);
        }
        // cout<<max1<<" ";
        ans += (grup - max1);
    }
    cout << ans/2 << "\n";
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