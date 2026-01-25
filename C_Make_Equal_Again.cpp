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
    vector<int> uzi;
    for(int i = 0; i < n; i++){
        int ele; 
        cin>>ele;
        uzi.pb(ele);
    }
    if(n == 1){cout<<"0"<<endl; return;}
    int count = 1;
    for(int i = 0; i < n - 1; i++){
        if(uzi[i] == uzi[i+1]){
            count++;
        }
        
        else{break;}
    }
    int countbttm = 1;
    for(int i = n - 1; i > 0; i--){
        if(uzi[i] == uzi[i - 1]){
            countbttm++;
        }
        
        else{break;}
    }
    if(uzi[0] == uzi[n-1]){
        count = count + countbttm;
    }
    int maxi = max(countbttm, count);
    cout<<max(n-maxi, 0)<<endl;
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