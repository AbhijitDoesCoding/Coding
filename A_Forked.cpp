#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    int c;
    cin>>c;
    while(c--){
        solve();
    }
}
int sx[4] = {1, 1, -1, -1}, sy[4] = {-1, 1, -1, 1};
void solve(){
    int a, b, x1, x2, y1, y2;
    cin>>a>>b>>x1>>y1>>x2>>y2;
    set< pair<int, int> > king, queen;
    for(int i = 0; i < 4; i++){
        king.insert({x1 - sx[i] * a, y1 - sy[i] * b});
        queen.insert({x2 - sx[i] * a, y2 - sy[i] * b});
        king.insert({x1 - sx[i] * b, y1 - sy[i] * a});
        queen.insert({x2 - sx[i] * b, y2 - sy[i] * a});
    }
    int count  = 0;
    for(auto x : king)
    if(queen.find(x) != queen.end())
    count++;
    cout<<count<<endl;
}
