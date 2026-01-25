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
    cin >> n;
    vector<string> v(n);
    loop(i, 0, n){
        cin >> v[i];
    }
    char a = v[0][0];
    char b = v[0][1];
    if(a == b){
        cout << "NO\n";
        return;
    }
    loop(i, 0, n){
        loop(j, 0, n){
            if(i == j || i+j == n-1){
                if(v[i][j] != a){
                    cout << "NO\n";
                    return;
                }
            }else{
                if(v[i][j] != b){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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