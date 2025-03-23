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
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int m=t.length();
    int i=0,j=0;
    while(i<n && j<m){
        if(s[i]!=t[j]){
            cout<<"NO\n";
            return;
        }
        int cnt1=0,cnt2=0;
        while(i<n && s[i]==s[i+1]){
            i++;
            cnt1++;
        }
        while(j<m && t[j]==t[j+1]){
            j++;
            cnt2++;
        }
        if(cnt1>cnt2){
            cout<<"NO\n";
            return;
        }
        i++;
        j++;
    }
    if(i<n || j<m){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    
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