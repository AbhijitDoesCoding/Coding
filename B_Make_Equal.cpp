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
    int n;
    cin>>n;

    int maxi = -1, mini = -1;
    int hsum = 0;
    int left_min = INT_MAX;
    int left_max = INT_MAX;
    int l = INT_MAX;
    int k = INT_MIN;
    vector<int> sec;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        l = min(l , ele);
        k = max(k , ele);
        hsum += ele;
        sec.pb(ele);
    }
    if(l == k){yes return;}
    int bal = 0;
    int sum = hsum / n;
    for(int i = 0; i < n; i++){
        if(sec[i] > sum){
            bal = bal + sec[i] -  sum;
        }
        if(sec[i] < sum){
            bal = bal - (sum - sec[i]);
        }
        if(bal < 0){
            no return;
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