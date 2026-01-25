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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve(){
int a , b, l;
cin>>a>>b>>l;
int uzi = gcd(a, b);
int ax = 0; int bx = 0;
int y = l; int z = l;
int m = min(a, b);
int n = max(a, b);
while(y > 0){
    if(y % n == 0){
        y = y / n;
        bx++;
    }
    else break;
}

while(y > 0){
    if(y % m == 0){
        y = y / m;
        ax++;
    }   
    else break;
}
int u = (pow(a, ax))*(pow(b, bx));
int final = (ax+1)*(bx + 1);
if(uzi > 1 && a != b && l % a == 0 && l % b == 0){final++;}


cout<<final<<endl;
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