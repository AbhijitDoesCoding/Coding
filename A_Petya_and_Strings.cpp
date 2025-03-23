#include<bits/stdc++.h>
using namespace std;

void func(){
    string a, b;
    cin>>a>>b;
    int u, v;
    u = a.size();
    int z = 0;
    
    transform(a.begin(), a.end(), a.begin(), ::tolower);
     transform(b.begin(), b.end(), b.begin(), ::tolower);
     for(int i = 0; i < u; i++){
        if(a[i] > b[i]){
            z = 1;
            break;
        }
        else if(a[i] < b[i]){
            z= -1;
            break;
        }
        else{

        }
     }
     cout<<z<<endl;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
