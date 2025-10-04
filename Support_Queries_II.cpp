#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Bag {
    ll k;
    multiset<ll> kset, notkset;
    ll ans = 0;

    void insert(ll x) {
        kset.insert(x);
        ans += x;

        if (kset.size() > k) {
            auto it = kset.begin();
            ans -= *it;
            notkset.insert(*it);
            kset.erase(it);
        }
    }

    void remove(ll x) {
        auto it = kset.find(x);
        if (it != kset.end()) {
            ans -= *it;
            kset.erase(it);
            if (!notkset.empty()) {
                auto largest = prev(notkset.end());
                ans += *largest;
                kset.insert(*largest);
                notkset.erase(largest);
            }
            return;
        }

        it = notkset.find(x);
        if (it != notkset.end()) {
            notkset.erase(it);
        }
    }

    ll getSum() {
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll q, k;
    cin >> q >> k;

    Bag bag;
    bag.k = k;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            bag.insert(x);
        } else if (type == 2) {
            ll x;
            cin >> x;
            bag.remove(x);
        } else if (type == 3) {
            char c;
            cin >> c;
            cout << bag.getSum() << "\n";
        }
    }

    return 0;
}
