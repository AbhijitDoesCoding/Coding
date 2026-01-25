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
    
    set<int>temp;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        temp.insert(ele);
    }
    vector<int> uzi(temp.begin(), temp.end());

    int curr = -1; int final = 0;
    int count = 0;
    for(int i = 0; i < uzi.size() - 1; i++){
      
        int k = uzi[i + 1] - uzi[i];
        if( k < n){
        if(k == curr && i != uzi.size() - 2){
            count = max(3, ++count);
            final = max(count, final);
            curr = k;
        }
        
        else{
            count = 1;
            curr = k;
        }
        }
    }
    cout<<max(++final, 1)<<endl;
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