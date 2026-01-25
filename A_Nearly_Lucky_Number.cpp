#include<bits/stdc++.h>
using namespace std;

void func(){
    long long input, uzi;
    cin>>input;
    int z = 0, u = 0;
    while(input > 0){
        uzi = input % 10;
        if(uzi == 4 || uzi == 7){
            z++;
        }
        input = input / 10;
    }
    if(z == 4 || z == 7){
        cout<<"YES";
    }
    else cout<<"NO";
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
