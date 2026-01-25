#include<bits/stdc++.h>
using namespace std;

void func(){
int n, t;
cin>>n>>t;
string order;
cin>>order;
for(int i = 0; i< t; i++){
    for(int j = 0; j < n - 1; j++){
        if(order[j] == 'B' && order[j+1] == 'G'){
            swap(order[j], order[j+1]);
            j++;
        }
    }
}
    cout<<order<<endl;

}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
    return 0;
}
