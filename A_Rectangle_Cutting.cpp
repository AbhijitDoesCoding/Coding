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
    int a, b;
    cin>>a>>b;
    int k = 0;
    int l;
    if(a % 2 == 0){
        k = a/2;
        l = b;
    }
    else if(b % 2 == 0){
        k = b /2;
        l = a;
    }
    else{
        no;
        return;
}
    if(k == l){
        if(b%2 == 0){
            k = b / 2;
            l = a;
            if(k == l){
                no
                return;
            }
            else{
                yes return;
            }
        }
        
        no
        return;
    }
    else {
        yes
        return;
    }

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
