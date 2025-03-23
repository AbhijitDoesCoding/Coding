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
    string s;
    cin>>s;
    ll ans = INT_MAX;
    ll n=s.size();
    ll zero = -1, count =2, great = -1;
    rev(i, 0, n){
        if(s[i] == '0' && count > 0){
            
            if(count == 1){
            zero = i;
            break;
            }
            if(count == 2)
            great = i;
            count--;
        }
    }
    if(zero != -1 && great != -1 && zero < great){
                ans = min(ans, great - zero - 1 + n - 1 - great);
            }
            ll count1 = 2, two = -1, five = -1;
            rev(i, 0, n){
                if(s[i] == '5' && count1 == 2){
                    five = i;
                    count1--;
                }
                if(s[i] == '2' && count1 == 1){
                    two = i;
                    count1--;
                    break;
                    }
            }
    if(two != -1 && five != -1 && five > two){
            ans = min(ans, five - two -1 + n - 1 - five);
        }
         ll count2 = 2, seven = -1, five1 = -1;
            rev(i, 0, n){
                if(s[i] == '5' && count2 == 2){
                    five1 = i;
                    count2--;
                }
                if(s[i] == '7' && count2 == 1){
                    seven = i;
                    count2--;
                    break;
                    }
            }
        if(seven != -1 && five1 != -1 && five1 > seven){
            ans = min(ans, five1 - seven - 1 + n - 1 - five1);
        }
    // now for 50
     ll count3 = 2, five2 = -1, zero1 = -1;
            rev(i, 0, n){
                if(s[i] == '0' && count3 == 2){
                    zero1 = i;
                    count3--;
                }
                if(s[i] == '5' && count3 == 1){
                    five2 = i;
                    count3--;
                    break;
                    }
                    // cout<<i<<" ";
            }
        if(five2 != -1 && zero1 != -1 && zero1 > five2){
            ans = min(ans, zero1 - five2 - 1 + n - 1 - zero1);
            }
            
            
    cout<<ans; nline;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}