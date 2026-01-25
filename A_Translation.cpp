#include<bits/stdc++.h>
using namespace std;

void func(){
    string s, p , d;
    cin>>s>>p;
    d = s;
    for(int i = 0; i < s.size(); i++){
        d[i] = p[s.size() - i - 1];
    }
    if( d == s) cout<<"YES";
    else cout<<"NO";

}
int main(){
    long c;
    c = 1;
    while(c--){
        func();
    }
}
