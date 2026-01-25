#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int z = 0;
    map <char , int> occ;
    for(auto ch : s ){
        occ[ch]++;
    }
    for(auto uz : occ){
        if(uz.second % 2 == 1){
            z++;
        }
    }
    z = max(z - k, 1);
    if(z > 1){
        cout<<"NO"<<endl;
    }
    else {cout<<"YES"<<endl;}
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
