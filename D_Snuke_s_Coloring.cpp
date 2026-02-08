#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> pi;

void solve(){
    ll h, w; 
    cin >> h >> w;

    ll n; 
    cin >> n;

    map<pi, ll> v;

    for(ll k = 0; k < n; k++){
        ll x, y; 
        cin >> x >> y;
        for(ll dx = -2; dx <= 0; dx++){
            for(ll dy = -2; dy <= 0; dy++){
                ll nx = x + dx;
                ll ny = y + dy;
                if(nx >= 1 && nx <= h-2 && ny >= 1 && ny <= w-2){
                    v[{nx, ny}]++;
                }
            }
        }
    }

    vector<ll> ans(10, 0);

    for(auto &p : v){
        ans[p.second]++;
    }

    ll total = (h - 2) * (w - 2);

    ans[0] = total;
    for(int i = 1; i <= 9; i++){
        ans[0] -= ans[i];
    }

    for(int i = 0; i <= 9; i++){
        cout << ans[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
