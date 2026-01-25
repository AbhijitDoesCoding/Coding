#include<bits/stdc++.h>
using namespace std;

void func(){
    int n , k ;
    cin >> n>> k;
    for(int i = 0; i < k ; i++){
        if(n % 10 != 0){
            n--;
        }
        else 
        n = n/10;
    }
            cout<<n;

}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
