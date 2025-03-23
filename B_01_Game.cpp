
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
    string s;
    cin>>s;
    int c0 = 0, c1 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            c0++;
        }
        else{c1++;}
    }
    int uzi =  min(c0, c1);
    if(uzi % 2 == 0){
        cout<<"NET\n";
    }
    else{
        cout<<"DA\n";
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}