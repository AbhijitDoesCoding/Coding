#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    string well;
    cin>>n>>well;
    int count = 0;
    int j = 0;
    int uzi = 1;
    int cont = 0;
    for(int i = 0; i < n; i++){
        
        if(well[i] == '.'){
          j++;
          cont++; 
        }
        else{
            cont = 0;
        }
        if(cont > 2){
            cout<<"2"<<endl;
            uzi = 0;
            break;
        }

        }
        if(uzi == 1){
            cout<<j<<endl;
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
