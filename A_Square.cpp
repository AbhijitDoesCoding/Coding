#include<bits/stdc++.h>
using namespace std;

void func(){
   
    int x, y;
    int u , v;
    int j = 0;
   for(int i = 0; i < 4; i++){
        cin>>x>>y;
        if(j == 0){
            u = x;
            j++;
        }
        if(x != u){
            v = x;
        }
   }
    int area = abs(v - u);
    int area1 = area * area;
    cout<<area1<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
}
