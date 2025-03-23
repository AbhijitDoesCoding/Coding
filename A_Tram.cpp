#include<bits/stdc++.h>
using namespace std;

void func(){
    int n;
    cin >> n;  // You need to read the value of n before using it.
    
    int max_ps = INT_MIN;
    // cout<<max_ps<<endl;
    int enter, exit;
    int current = 0;
    // cout<<current<<endl;
    for(int i = 0; i < n; i++){
        cin >> enter;
        cin >> exit;
        // cout<<enter<<" "<<exit<<endl;
        current = exit - enter + current;
        // cout<<current<<endl;
        max_ps = max(max_ps, current);
    }
    cout << max_ps;
}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
return 0;
}