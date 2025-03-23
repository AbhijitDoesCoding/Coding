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
    ll n; char c;
    cin>>n>>c;
    string s; cin>>s;
 
    ll count = -1;
    loop(i, 0, n){
        if(s[i] == 'g'){
             count = i;
             break;
        }
    }
    ll done = 0;
    ll curr = count;
    ll maxsofar = 0;
    loop(i, 0, s.size()){
        if(s[i] == c){
            if(curr > i && done == 0){
                done = 1;
                maxsofar = max(maxsofar, curr - i);
            }
            else if(curr < i){
                done = 0;
                loop(j, i, n){
                    if(s[j]== 'g'){
                        curr = j;
                        maxsofar = max(maxsofar, curr - i);
                        done = 1;
                        break;
                    }
                }
                if(done == 0){
                    ll baadka = n - i + count;
                    maxsofar = max(maxsofar, baadka);
                    cout<<maxsofar; nline; return;
                }
            }
        }
    }
    cout<<maxsofar; nline; 
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