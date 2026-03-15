#include<bits/stdc++.h>
using namespace std; typedef long long ll;

#define nline cout<<"\n";
#define yes cout<<"Yes\n";
#define no cout<<"No\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define loop(i,l,h) for(int i=l;i<h;i++)
#define rev(i,l,h) for(int i=h-1;i>=l;i--)
#define mod 1000000007

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi; typedef pair<ll,ll> pi;

bool blocked[14][14];
bool rblocked[14][14];
ll ans;
vi p;
ll n;
vector<pi> v;

bool check(ll row,ll col){

    if(blocked[row][col]) return false;

    loop(i,0,row){
        if(p[i]==col) return false;
        if(abs(i-row)==abs(p[i]-col)) return false;
    }

    return true;
}

void rec(ll row){

    if(row==n){
        ans++;
        return;
    }

    loop(col,0,n){

        if(check(row,col)){

            p.pb(col);

            vector<pi> changed;

            for(auto k: v){

                ll i = row + k.ff;
                ll j = col + k.ss;

                if(i>=0 && i<n && j>=0 && j<n && !blocked[i][j] && !rblocked[i][j]){
                    blocked[i][j] = true;
                    changed.pb({i,j});
                }
            }

            rec(row+1);

            for(auto &x: changed){
                blocked[x.ff][x.ss] = false;
            }

            p.pop_back();
        }
    }
}

void solve(){

    cin>>n;

    ans = 0;
    p.clear();

    v.pb({-2,1});
    v.pb({-2,-1});
    v.pb({2,1});
    v.pb({2,-1});
    v.pb({-1,2});
    v.pb({1,2});
    v.pb({-1,-2});
    v.pb({1,-2});

    loop(i,0,n){
        loop(j,0,n){
            blocked[i][j] = false;
        }
    }

    loop(i,0,n){
        loop(j,0,n){
            char c;
            cin>>c;
            rblocked[i][j] = (c=='*');
        }
    }

    rec(0);

    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    while(t--) solve();
    return 0;
}