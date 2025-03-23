#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll final_position(ll x0, ll n) {
    if (n == 0) return x0;

    ll cycle = n / 4;
    ll remainder = n % 4;

    ll displacement = 0;

    if (x0 % 2 == 0) {
        // Even starting point
        if (remainder == 1) displacement = -n;
        else if (remainder == 2) displacement = 1;
        else if (remainder == 3) displacement = n + 1;
    } else {
        // Odd starting point
        if (remainder == 1) displacement = n;
        else if (remainder == 2) displacement = -1;
        else if (remainder == 3) displacement = -(n + 1);
    }

    return x0 + displacement;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll x0, n;
        cin >> x0 >> n;
        cout << final_position(x0, n) << "\n";
    }

    return 0;
}
