#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll m; ll n;
    cin>>n>>m;
    string s; cin>>s;
    vi a(7,0);
    for(ll i = 0; i < n; i++){
        if(s[i] == 'A'){
            a[0]++;
            }
            else if(s[i] == 'B'){
                a[1]++;
                }
                else if(s[i] == 'C'){
                    a[2]++;
                }
                else if(s[i] == 'D'){
                    a[3]++;
                    }
                    else if(s[i] == 'E'){
                        a[4]++;
                        }
                        else if(s[i] == 'F'){
                            a[5]++;
                            }
                            else{
                                a[6]++;
                                }
    }
    ll count = 0;
    for(ll i = 0; i < 7; i++){
        if(a[i] < m)
            count += m - a[i];
    }
    cout<<count<<endl;
}   
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}