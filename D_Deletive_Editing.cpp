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
    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();
    vi uzi(26);
    string temp = "";
    loop(i, 0, m){
        uzi[t[i]-'A']++;
    }
    rev(i, 0, n){
        if(uzi[s[i]-'A'] > 0){
            temp += s[i];
            uzi[s[i]-'A']--;
        }
    }
    reverse(all(temp));
    if(temp == t){
        yes return;
    }
    no return;
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