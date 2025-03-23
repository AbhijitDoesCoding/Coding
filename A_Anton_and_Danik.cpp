#include<bits/stdc++.h>
using namespace std;

void func(){
    int size0;
    string win;
    cin>>size0>>win;
    int anton = 0, danik = 0;
    for(int i = 0; i < size0; i++){
        if(win[i] == 'A'){
            anton++;
        }
        else{
            danik++;
        }
    }
    if(anton > danik) cout<<"Anton";
    else if(danik > anton) cout<<"Danik";
    else cout<<"Friendship";
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
