#include<bits/stdc++.h>
using namespace std;

void func(){
    int a, b, year = 0;
    cin >> a >> b;
    while(b >= a){
        a = a*3;
        b = b*2;
        year++;
    }
    cout<<year;
}
int main(){
    long c;
    c =1 ;
    while(c--){
        func();
    }
}
