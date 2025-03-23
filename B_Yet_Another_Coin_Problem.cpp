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
int opt(int z){
    if(z == 0) return 0;
    if(z >= 15){
        int uzi = z / 15;
        return uzi + opt(z%15);
    }
    if(z >= 10){
        int  uzi = z /10;
        return uzi + opt(z%10);
    }
    if(z >= 6){
        int uzi = z /6;
        return uzi + opt(z%6);
    }
    if(z >= 3){
        int uzi = z/ 3;
        return uzi + opt(z%3);
    }
    if(z >= 1){
        int uzi = z / 1;
        return uzi + opt(z%1);
    }
}
void solve(){
    int n;
    cin>>n; 
// , 1
// , 3
// , 6
// , 10
// , 15
    // int count = 0;
    // while(n>0){
    //     if(n > 14){
    //         n -= 15;
    //     }
    //     else if(n > 9){
    //         n-=10;
    //     }
    //     else if(n > 5){
    //         n-=6;
    //     }
    //     else if(n > 2){
    //         n-=3;
    //     }
    //     else{
    //         n-=1;
    //     }
    //     count++;
    // }
    // cout<<count<<endl;
    int q = opt(n); cout<<q<<endl;
}   
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}