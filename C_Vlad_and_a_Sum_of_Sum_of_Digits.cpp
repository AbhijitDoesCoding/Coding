#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)

int solve(int uzi){
    if(uzi < 10) return uzi*(uzi+1)/2;
    int count = log10(uzi);

    int final[count+1];
    final[0] = 0;
    final[1] = 45;
    for(int i = 2; i <= count; i++){
        final[i] = final[i - 1]*10 + 45 * ceil(pow(10, i - 1));
      
    }
    int z = ceil(pow(10, count));
    int last = uzi / z;
    int ans = last * final[count] + solve(uzi % z) + last * (1 + uzi % z) + (last*(last - 1)/2)*z;
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int z = solve(n);
        cout<<z<<endl;
    }
    return 0;
}