#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    int z = 0;
    string a,b,c;
    cin>>n>>a>>b>>c;
    for(int i = 0; i < n; i++){
        if(a[i] == c[i] && b[i] == c[i] ){
            z++;
        }     
    }
    if(z>0){
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
