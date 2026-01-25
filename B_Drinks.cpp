#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, j;
    cin>>n;
    double k = 0;
    for(int i = 0; i < n; i++){
        cin>>j;
        k = k + j;
        
    }
    printf("%.12f\n", k/n);
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
return 0;
}
