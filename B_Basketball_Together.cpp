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
        ll N, D;
    cin >> N >> D;

    vector<ll> powers(N);
    for (ll i = 0; i < N; i++) {
        cin >> powers[i];
    }

    sort(powers.begin(), powers.end(), greater<ll>());

    ll maxWins = 0;
    ll count = 0;
    for (ll i = 0; i < N; i++) {
        if(D < powers[i]){
            maxWins++;
            count++;
            
        }
        else{

            if(N == 0){
                cout<<maxWins<<endl;
                return;
            }
            else{
                ll needed = D / powers[i] + 1; 
            
                count += needed;
                if(count > N){
                    count -= needed; 
                    cout<<maxWins<<endl;
                    return;
                }
                else if(count == N){
                    maxWins++;
                    cout<<maxWins<<endl;
                    return;
                }
                else{
                    maxWins++;
                }
            }
        }
    }

    cout << maxWins << endl;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    // cin>>t;

    while(t--){
        solve();
    }
    return 0;
}