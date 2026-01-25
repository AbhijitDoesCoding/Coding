#include<bits/stdc++.h>
using namespace std;

void func(){
    long long n;
    cin>>n;
    if(n == 0){
        cout<<n;
    }
    else if(n % 2 == 0){
        cout<<n/2;
    }
    else {
        cout<<(n/2 + 1)*(-1);
    }
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
