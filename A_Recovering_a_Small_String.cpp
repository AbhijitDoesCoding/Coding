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

    if(n / 26 == 0){
    char uzi = n - 2 + 96;
        cout<<"aa"<<uzi<<endl;
    return;
    }
    else if( n / 26 == 1){
         
        
        if(n - 1 > 26){
            cout<<"a";
            char uzi = n - 1 - 26 + 96;
            char jj = n - (n - 1 - 26 + 1) + 96;
            cout<<uzi<<jj<<endl;
        }
        else if(n - 1 == 26){cout<<"aay"<<endl;}
        else if(n  - 1 == 27){cout<<"aaz"<<endl;}
        if(n - 1 == 25){
                        cout<<"a";

            cout<<"ax"<<endl;
        }
    }
    else if(n == 52){
        cout<<"ayz"<<endl;
    }
    else if(n == 53){
        cout<<"azz"<<endl;
    }
    else if(n == 54){
        cout<<"bzz"<<endl;
    }
    else if(n == 78){
        cout<<"zzz"<<endl;
    }
    else{
        char uzi = n - 52 + 96;
        cout<<uzi<<"zz"<<endl;

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