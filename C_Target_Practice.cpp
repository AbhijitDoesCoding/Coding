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
    int total = 0;
    loop(i, 0, 100){
        char ele;
        cin>>ele;
        if(ele == 'X')
        {
            if((i >= 0 && i < 10) || (i >= 90 && i <100) || i % 10 == 0 || i % 10 == 9){
                total += 1;
            }
            else if((i >= 11 && i < 19) || (i >= 81 && i < 89) || (i % 10 == 1 || i % 10 == 8)){
                total += 2;
            }
            else if((i >= 22 && i < 28) || (i >= 72 && i < 78) || (i % 10 == 2 || i % 10 == 7)){
                total += 3;
            }
            else if ((i >= 33 && i < 37) || (i >= 63 && i < 67) || (i % 10 == 3 || i % 10 == 6)){
                total += 4;
            }
            else if((i >= 44 && i < 46) || (i >= 54 && i < 56)){
                total += 5;
            }
        }
    }
    cout<<total<<endl;
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