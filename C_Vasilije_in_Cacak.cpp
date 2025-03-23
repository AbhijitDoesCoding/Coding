#include<bits/stdc++.h>
using namespace std;

void func(){
    long long n, k, x;
    cin>>n>>k>>x;
    long long max, min;
    max = n*(n+1)/2;
    min = k*(k+1)/2;
    long long uzk = max - ((n - k)*(n-k+1)/2);
    if(x >= min && x <= uzk){
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
