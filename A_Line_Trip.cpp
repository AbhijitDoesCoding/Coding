#include<bits/stdc++.h>
using namespace std;

void func(){
    int n, x;
    cin>>n>>x;
    int diff = 0;
    int ele;
    int z =0;
    for(int i = 0; i < n; i++){
        cin>>ele;
        diff = max(diff, ele - z);
        z = ele;
    }
    cout<< max(diff, 2*(x - ele))<< endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
