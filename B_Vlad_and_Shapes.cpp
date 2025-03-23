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
    ll n;
    cin>>n;
    string s;
    int maxi = 0;
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        maxi = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == '1') 
            maxi++;
        }
        if(maxi == 0)
        maxi = 2;
        mini = min(mini, maxi);
        // cout<<mini<<endl;
        }
        if(mini == 1){
            cout<<"TRIANGLE"<<endl;
        }
        else cout<<"SQUARE"<<endl;
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