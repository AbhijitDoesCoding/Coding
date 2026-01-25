#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> lastOccurrence;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        lastOccurrence[arr[i]] = i;
    }

    int q;
    cin >> q;
    
    while(q--){
        int l, r;
        cin >> l >> r;

        bool found = false;
        int lans = -1, rans = -1;

        for(int j = l - 1; j < r; j++){
            if(j < r - 1 && arr[j] != arr[j + 1]){
                lans = j+1;
                rans = j+2;
                found = true;
                break;
            }
            if(j == r - 1 && lastOccurrence[arr[j]] < l - 1){
                lans = r;
                rans = r + 1;
                found = true;
                break;
            }
        }

        if(found) {
            cout << lans << " " << rans << endl;
        } else {
            cout << "-1 -1" << endl;
        }   
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

