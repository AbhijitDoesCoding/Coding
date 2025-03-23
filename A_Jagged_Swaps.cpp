#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin>>n;
    vector<int> uzi;
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        int ele;
        cin>>ele;
        uzi.push_back(ele);
        mini = min(uzi[i], mini);
    }
    if(mini == uzi[0]){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main(){
    long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
