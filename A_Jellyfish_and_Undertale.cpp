#include<bits/stdc++.h>
using namespace std;

void func(){
    long long a, b, n;
    cin>>a>>b>>n;
    vector<int> esp;
    long long c;
    c = b;
    long long count = b;
    for(int i = 0; i < n; i++){
        long long ele; cin>>ele;
        ele = min(a - 1, ele);
            count += ele;
    }
    
    cout<<count<<endl;
}
int main(){
    long long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
