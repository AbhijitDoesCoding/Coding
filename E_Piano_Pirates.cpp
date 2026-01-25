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
    ll n, m;
    cin>>n>>m;
    vi a(m);
    loop(i,0,m) cin>>a[i];
    vector<vector<ll>> v(n, vector<ll>(m));
    loop(i,0,n){
        loop(j,0,m){
            cin>>v[i][j];
        }
    }
    ll k = 0;
    ll index = -1;
    loop(i, 0, n){
        if(index != -1) break;
        loop(j, 0, m){
            if(index != -1) break;
            if(v[i][j] == a[k]){
                ll u = j;
                while(k < m){
                    if(v[i][u] == a[k]){
                        k++;
                        u++;
                        u %= m;
                        if(k == m){
                            index = i;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

    if(index == -1){
        cout<<-1;
        return;
    }
    cout<<index+1;
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