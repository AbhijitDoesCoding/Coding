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
void solve(){
    int n;
    cin>>n;
    char au = 'a';
    string s;
    vector<int> trace(n);
    int j = 0;
    vector<char> charVector(n, 'a');
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        s.pb(charVector[ele]);
        charVector[ele]++;
    }
cout<<s<<endl;
    }

    

int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
