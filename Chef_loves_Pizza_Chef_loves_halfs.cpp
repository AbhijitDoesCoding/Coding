#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll,ll> pi;

void solve(){
    // Your code here
    ll n;
    cin >> n;
    ll cuts = n/2;
    // if cuts = 1 then closest_less_than_or_equal_to_power_of_2 = 0
    // if cuts = 7 then closest_less_than_or_equal_to_power_of_2 = 2
    // if cuts = 8 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 9 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 10 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 11 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 12 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 13 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 14 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 15 then closest_less_than_or_equal_to_power_of_2 = 3
    // if cuts = 16 then closest_less_than_or_equal_to_power_of_2 = 4
    ll closest_less_than_or_equal_to_power_of_2 = 0;
    while(pow(2,closest_less_than_or_equal_to_power_of_2) <= cuts){
        closest_less_than_or_equal_to_power_of_2++;
    }
    if(pow(2,closest_less_than_or_equal_to_power_of_2) != cuts){
        closest_less_than_or_equal_to_power_of_2--;
    }
    closest_less_than_or_equal_to_power_of_2 = pow(2,closest_less_than_or_equal_to_power_of_2);
    // cout<<closest_less_than_or_equal_to_power_of_2; nline;
    cout<<(cuts - closest_less_than_or_equal_to_power_of_2)*4; nline;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}