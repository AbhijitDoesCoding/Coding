#include<bits/stdc++.h>
using namespace std;

void func(){
    int upper = 0, lower = 0;
    string uzi;
    cin>>uzi;
    for(int i = 0; i < uzi.size(); i++){
        if(isupper(uzi[i]))
        upper++;
        else lower++;
    }
    if(lower >= upper){
        transform(uzi.begin(), uzi.end(), uzi.begin(), ::tolower);
    }
    else {
         transform(uzi.begin(), uzi.end(), uzi.begin(), ::toupper);
    }
    cout<<uzi;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
