#include<bits/stdc++.h>
using namespace std;

void func(){
    int u, ul;
    cin>>u>>ul;
    if((u+ul) %2 == 0)
    cout<<"Bob";
    else
    cout<<"Alice";
    cout<<endl;
}
int main(){
    long long c;
    cin>>c;
    while(c--){
        func();
    }
}
