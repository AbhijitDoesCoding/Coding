#include<bits/stdc++.h>
using namespace std;

void func(){
    int k , n, w, dollars;
    cin>> k >>n>>w;
    dollars = (w)*(w+1)/2 * k;
    cout<< max(0, dollars - n);
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
