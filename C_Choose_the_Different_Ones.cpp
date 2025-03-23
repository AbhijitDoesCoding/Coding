#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
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
    int n, m, k;
    cin>>n>>m>>k;
    vector<int>nvec, mvec;
    vector<int>uzi(k, 0);
    vector<int>kzi(k, 0);
    int countn = 0, countm = 0;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        if(ele <= k){
        uzi[ele - 1]++;
        if(uzi[ele - 1] == 1)
        countn++;
        }
    }

    for(int i = 0; i < m; i++){
        int ele;
        cin>>ele;
        if(ele <= k){
        kzi[ele - 1]++;
        if(kzi[ele -1] == 1)
        countm++;        
        }
    }
    if(countn < k/2 || countm < k/2){
        no
        return;
    }
    for(int i = 0; i < k; i++){
        int ziu = uzi[i] + kzi[i];
        if(ziu < 1){
            no
            return;
        }
    }
    yes

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