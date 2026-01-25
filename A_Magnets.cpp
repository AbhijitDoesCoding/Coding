#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin>>n;
    int previous;
            int ele;
int u = 1;
int z = 0;
    for(int i = 0; i < n; i++){
        if(u == 0){
            previous = ele;
        }
        cin>>ele;
        while(u > 0){
        previous = ele;
        u = 0;
        }
        if(previous != ele){
            z++;
        }
    }
cout<<z+1;
}

int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
