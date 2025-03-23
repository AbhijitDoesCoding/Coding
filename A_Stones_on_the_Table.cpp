#include<bits/stdc++.h>
using namespace std;

void func(){
    int sto;
    string ones;
    int z = 0;
    cin>>sto>>ones;
    for(int i = 0; i < sto - 1; i++){
        if(ones[i] == ones[i+1]){
            z++;
        }
    }
    cout<<z;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
