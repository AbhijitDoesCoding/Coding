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

// void solve(){
//     // Your code here
//     string s;
//     cin>>s;
//     int n=s.length();
//     loop(i,0,n){
//         s[i]=max(s[i], (char)('9'-s[i]+'0'));
//     }
//     cout<<s;
// }
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    loop(i, 0, n) {
        int digit = s[i] - '0'; 
        int inverted = 9 - digit; 
        if (inverted < digit && !(i == 0 && inverted == 0)) { 
            s[i] = inverted + '0'; 
        }
    }
    cout << s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}