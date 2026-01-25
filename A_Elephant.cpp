#include<bits/stdc++.h>
using namespace std;

void func(){
    int a;
    cin>>a;
    if(a %5 != 0){
    a = a/5;
    cout<< a + 1;}
    else{
        a = a/5;
        cout<<a;
    }
}
int main(){
    long c;
    c =1;
    while(c--){
        func();
    }
}
