#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, f, a, b;
    cin>>n>>f>>a>>b;
    vector<int> eles;
    
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        eles.push_back(ele);
    }
    int msg = 0;
    for(int i = 0; i < n; i++){
        int timeDiff;
        if(i == 0){
            timeDiff = eles[i];
        }
        else{
            timeDiff = eles[i] - eles[i - 1];
        }
        int energyc;
        if((timeDiff*a) <= b){
            energyc = timeDiff*a;
        }
        else energyc = b;
        if(energyc >= f){
            f -= energyc;
            msg++;
        }
        else break;
    }
if (msg == n){cout<<"YES"<<endl;}
else cout<<"NO"<<endl;
}
    
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
}
