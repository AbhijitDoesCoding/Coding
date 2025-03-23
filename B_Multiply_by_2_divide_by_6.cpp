#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back

void func(){
    ll n;
    cin>>n;
    if( n == 1) {
        cout<<"0"<<endl;
        return;
    }
    if( n % 3 != 0){
        cout<<"-1"<<endl;
        return;
    }
    ll count3 = 0; ll count2 = 0;
    ll uzi = n, uzii = n;
    while (uzi % 3 == 0 && uzi != 0) {
        uzi /= 3;
        count3++;
    }
    while (uzii % 2 == 0 && uzii != 0) {
        uzii /= 2;
        count2++;
    }
  
    // cout<<count3<<" "<<count2<<" "<<endl;
    if(count2 > count3){
        cout<<"-1"<<endl;
    }
    else{
        ll final = count3 - count2;
        for(int i = 0; i< final; i++){
            n *= 2;
        }
        for(int i = 0; i < count3; i++){
            n /= 6;
        }
        if(n == 1){
            final += count3;
            cout<<final<<endl;
    }
        
        else 
        cout<<"-1"<<endl;
    }
}
int main(){
    ll c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
