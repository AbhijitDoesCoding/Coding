#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin>>n;
    map<int, int> occ;
    for(int i = 0; i < n; i++){
        int x; 
        cin>>x;
        occ[x]++;
    }
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
