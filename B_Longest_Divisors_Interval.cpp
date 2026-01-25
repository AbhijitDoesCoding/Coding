#include<bits/stdc++.h>
using namespace std;

void func(){
    long long n;
    cin>>n;
    long long count = 0;
    long long uzi = 0;
    for(int i = 1; i <= 100; i++){
        if(n % i == 0){
            count++;
        }
        else{
            uzi = max(uzi, count);
            count = 0;
        }
    }
    cout<<uzi<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
