#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
void solve(){
    int n; cin>>n;vector<char> uzi;
    string sl; cin>>sl;
    unordered_set<char> s, l;
    for(int i = 0; i < n; i++){
        if(islower(sl[i]))
            s.insert(sl[i]);
        else l.insert(tolower(sl[i]));
    }
    
    for(auto it = s.begin(); it != s.end(); ++it){ 
        if(l.count(*it) > 0) uzi.pb(*it);
    }
    sort(all(uzi));
    if(uzi.size() == 0) {cout<<"0"<<'\n'; return;}
    cout<<char(toupper(uzi[uzi.size() - 1]))<<'\n';
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}
