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
    ll n, k, b, s;
    cin>>n>>k>>b>>s;
    vi a(n);
    ll first_number = b*k+(k-1);

    if(s / k < b){
        cout<<-1<<endl;
        return;
    }
    if(k == 1){
        if(first_number < s){
            cout<<-1<<endl;
            return;
        }
    }
    if(first_number >= s){
        cout<<s<<" ";
        loop(i, 1, n){
            cout<<0<<" ";
        }
        nline; return;
    }
    else{
        ll ans = s;
        ans -= first_number; 
        ll temp = ans / (k - 1);
        if(ans % (k-1)) temp++;
        if(temp > (n-1)){
            cout<<-1<<endl;
            return;
        }
        loop(i, 0, n){
            if(i == 0){
                cout<<first_number<<" ";
            }
            else{
                if(ans >= (k - 1)){
                    cout<<(k-1)<<" ";
                    ans -= (k - 1);
                }
                else{
                    cout<<ans<<" ";
                    ans = 0;
                }
            }
        }
        nline;
        return;
    }
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