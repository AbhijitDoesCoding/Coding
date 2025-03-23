#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back

void func(){
    ll n;
    cin>>n;
    string x;
    cin>>x;
    ll great = 0, count = 0;
    
    for(ll i = 0; i < n - 1; i++){
        if(x[i] == x[i + 1]){
            count++;
            great = max(count, great);
        }
        else{
            count = 0;
            great = max(count, great);
        }
    }
    great += 2;
    cout<<great<<endl;
}
int main(){
    ll c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
