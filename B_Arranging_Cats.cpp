#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    string c, d;
    cin>>n>>c>>d;
    int zeros = 0; int ones = 0;
    for(int i = 0; i < n; i++){
        if(c[i] == d[i]){}
        else{
            if(c[i] == '0'){
                zeros++;
            }
            else ones++;
        }
    }
    cout<<max(zeros, ones)<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
