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
vi calc(ll need){
    vi ans;
    if(need == 1 || need == 2 || need == 3 || need == 6 || need == 7 || need == 10 || need == 11 || need == 14 || need == 15 || need == 17 || need == 18 || need == 19 || need == 22 || need == 23 || need == 26 || need == 27){
        ans.pb(-1);
        return ans;
    }
    else if(need == 4){
        ans.pb(1);
        ans.pb(0);
        return ans;
    }
    else if(need == 5){
        ans.pb(1);
        ans.pb(1);
        return ans;
    }
    else if(need == 8){
        ans.pb(2);
        ans.pb(1);
        return ans;
    }
    else if(need == 9){
        ans.pb(2);
        ans.pb(2);
        return ans;
    }
    else if(need == 12){
        ans.pb(3);
        ans.pb(2);
        return ans;
    }
    else if(need == 13){
        ans.pb(3);
        ans.pb(3);
        return ans;
    }
    else if(need == 16){
        ans.pb(4);
        ans.pb(3);
        return ans;
    }
    else if(need == 20){
        ans.pb(5);
        ans.pb(3);
        return ans;
    }
    else if(need == 21){
        ans.pb(5);
        ans.pb(4);
        return ans;
    }
    else if(need == 24){
        ans.pb(6);
        ans.pb(4);
        return ans;
    }
    else if(need == 25){
        ans.pb(6);
        ans.pb(5);
        return ans;
    }
}
void solve(){
    // Your code here
    ll n;
    cin>>n;

    if(n < 4){
        cout<<-1;
        return;
    }
    ll whites = 0;
    ll blacks = 0;
    ll needs = n/28;
    whites = needs * 7;
    blacks = needs * 5;
    ll need = n % 28;
    if(need != 0){
        vi more = calc(need);
        if(more[0] == -1){
            cout<<-1;
            return;
        }
        else{
            whites += more[0];
            blacks += more[1];
        }
    }
    cout<<whites<<" "<<blacks;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}