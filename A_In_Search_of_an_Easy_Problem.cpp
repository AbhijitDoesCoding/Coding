#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    int z = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        if(ele == 1){
            z++;
        }
        else
        {}
    }
    if(z > 0){
        cout<<"HARD";
    }
    else cout<<"EASY";
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
