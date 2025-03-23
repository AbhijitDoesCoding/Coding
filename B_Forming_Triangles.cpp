#include<bits/stdc++.h>
using namespace std;

void func(){
    long long n;
    cin>>n;
    vector<long long> u(n);
    for(long long i = 0; i < n; i++){
        cin>>u[i];
    }
    sort(u.begin(), u.end());
    long long triangles = 0;
    for(long long i = 0; i < n-2; i++){
        for(long long j = i + 1; j < n-1; j++){
            for(long long k = j + 1; k < n; k++){
                if(u[i] + u[j] > u[k] && u[i] > 0 && u[j] > 0 && u[k] > 0){
                triangles++;
            }
            else 
            {
            break;
                }
        }
    }
    
}
if(n == 1 || n==2){
    cout<<'0'<<endl;
}
else
cout<<triangles<<endl;
}

int main(){
    long long c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
