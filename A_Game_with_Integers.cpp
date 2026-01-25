
#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin>>n;
    if(n % 3 == 0){
        cout<<"Second"<<endl;
    }
    else cout<<"First"<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
