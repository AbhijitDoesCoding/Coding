#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back

void func(){
    ll n, k;
    cin>>n>>k;
    vector<ll> uzi;
    for(ll i = 0; i < n; i++){
        ll ele;
        cin>>ele;
        uzi.pb(ele);
    }
    sort(uzi.begin(), uzi.end());
    ll max1 = INT_MIN, count = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            count++;
            max1 = max(count, max1);
        }
        else{
        if(uzi[i] - uzi[i - 1] <= k){
            count++;
            max1 = max(count, max1);
        }
        else{
            count = 1;
        }
        }
    }
    max1 = n - max1;
    cout<<max1<<endl;
}
int main(){
    ll c;
    cin>>c;
    while(c--){
        func();
    }
    return 0;
}
