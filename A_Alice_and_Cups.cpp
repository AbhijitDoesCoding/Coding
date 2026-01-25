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
    // write your code here
    string s;
    cin>>s;
    int a = 1, b = 2, c = 3;
    loop(i, 0, s.size()){
        if(s[i] == 'A'){
            swap(a, b);
        }
        else if(s[i] == 'B'){
            swap(b, c);
        }
        else{
            swap(a, c);
        }
    }
    if(a == 1){
        cout<<1;
    }
    else if(b == 1){
        cout<<2;
    }
    else{
        cout<<3;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        // cout << "Case #" << t << ": \n";
        solve();
    }
    return 0;
}