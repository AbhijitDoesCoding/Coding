#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, a, b, c, d, z = 1, k;
    cin>>n;
    while(z > 0){
        n++;
        k = n;
        a = k % 10;
        k /= 10;
        b = k % 10;
        k /= 10;
        c = k % 10;
        k /= 10;
        d = k % 10;
        if(a == b || b == c || c == d || a == c || a == d || d == b){
            z = 1;
        }
        else z = 0;
    }
     cout<<n;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
