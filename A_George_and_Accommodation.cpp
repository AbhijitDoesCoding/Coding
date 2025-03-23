#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin>>n;
    int z = 0;
    for(int i = 0; i < n; i++){
        int u, k;
        cin>>u>>k;
        if(k - u >= 2){
            z++;
        }
    }
    cout<<z;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
