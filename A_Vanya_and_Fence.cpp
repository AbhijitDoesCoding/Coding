#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, h;
    cin>>n>>h;
    int width = 0;
    for(int i = 0; i<n;i++){
        int ele;
        cin>>ele;
        if(ele > h){
            width += 2;
        }
        else width++;
    }
    cout<<width;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
