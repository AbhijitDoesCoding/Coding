#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    string s, t;
    cin >> s >> t;
    vector<string> kzi;
    if(s[0]>t[0]){
        // cout<<"I am here 1\n";
        ll left = s[0] - t[0];
        // cout<<left<<"\n";
        if(s[1]>=t[1]){
            ll down = s[1] - t[1];
            cout<<max(down, left)<<"\n";
            while(down != 0 || left != 0){
                if(down != 0 && left != 0){
                    down--; left--;
                    cout<<"LD\n";
                }
                else if(down != 0){
                    down--;
                    cout<<"D\n";
                }
                else if(left != 0){
                    left--;
                    cout<<"L\n";
                }
            }
        }
        else if(s[1]<t[1]){
            
            ll up = t[1] - s[1];
            cout<<max(up, left)<<"\n";
            while(up != 0 || left != 0){
                if(up != 0 && left != 0){
                    up--; left--;
                    cout<<"LU\n";
                }
                else if(up != 0){
                    up--;
                    cout<<"U\n";
                }
                else if(left != 0){
                    left--;
                    cout<<"L\n";
                }
            }
        }
    }
    else if(s[0]<t[0]){
        // cout<<"I am here 2\n";
        ll right = t[0] - s[0];
        if(s[1]>=t[1]){
            ll down = s[1] - t[1];
            cout<<max(down, right)<<"\n";
            while(down != 0 || right != 0){
                if(down != 0 && right != 0){
                    down--; right--;
                    cout<<"RD\n";
                }
                else if(down != 0){
                    down--;
                    cout<<"D\n";
                }
                else if(right != 0){
                    right--;
                    cout<<"R\n";
                }
            }
        }
        else if(s[1]<t[1]){
            ll up = t[1] - s[1];
            cout<<max(up, right)<<"\n";
            while(up != 0 || right != 0){
                if(up != 0 && right != 0){
                    up--; right--;
                    cout<<"RU\n";
                }
                else if(up != 0){
                    up--;
                    cout<<"U\n";
                }
                else if(right != 0){
                    right--;
                    cout<<"R\n";
                }
        }                        
    }
}
    else if(s[0] == t[0]){
        if(s[1]>=t[1]){
            ll down = s[1] - t[1];
            cout<<down<<"\n";
            while(down != 0){
                down--;
                cout<<"D\n";
                }
                }
                else if(s[1]<t[1]){
                    ll up = t[1] - s[1];
                    cout<<up<<"\n";
                    while(up != 0){
                        up--;
                        cout<<"U\n";
                        }
                        }
                        }

    }
// cout<<kzi.size()<<"\n";
// loop(i, 0, kzi.size()){
//     cout<<kzi[i]<<"\n";
// }

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}