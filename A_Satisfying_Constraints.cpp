#include<bits/stdc++.h>
using namespace std;

void func(){
    int cons;
    cin>>cons;
    int greater, smaller;
    greater = INT_MIN;
    smaller = INT_MAX;
    set<int> equal;
    int z = 0;
    for(int i = 0; i < cons; i++){
            int k;
            cin>>k;
            int ut;
            cin>>ut;
            if(k == 1){
                greater = max(greater, ut);
            }
            else if(k == 2){
                smaller = min(smaller, ut);
            }
            else{
                equal.insert(ut);
            }
        }
          for (auto it = equal.begin(); it != equal.end(); it++) {
    if((*it) <= smaller && (*it) >= greater){
        z++;
    }
  }
        
        int final = max(0, smaller - greater + 1 - z);
        cout<<final<<endl;
        
    
}
int main(){
    int c;
    cin>>c;
    while(c--){
        func();
    }
return 0;
}
