#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define newline cout << "\n";
#define affirmative cout << "Yes\n";
#define negative cout << "No\n";
#define all_elements(x) x.begin(), x.end()
#define reverse_all(x) x.rbegin(), x.rend()
#define push_back_element push_back
#define make_pair_element make_pair
#define first_element first
#define second_element second
#define MODULO 1000000007
#define EULER 2.718281828459045235360
#define INFINITY 1e18
#define PI_CONST 3.1415926535897932384626
#define loop_forward(i, start, end) for (int i = start; i < end; ++i)
#define loop_backward(i, start, end) for (int i = end - 1; i >= start; --i)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vector_ll;
typedef pair<ll, ll> pair_ll;

void process() {
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    ll current = m - 1;
    ll flags = 0;
    ll counters = 0;

    int i = 0;
    while (i < n) {
        if (s[i] == 'L') {
            current = m;
        } else if (s[i] == 'W') {
            if (current <= 0) {
                ++counters;
            }
        } else {
            if (current <= 0) {
                ++flags;
            }
        }
        --current;
        ++i;
    }

    if (counters > k) {
        ++flags;
    }

    if (flags > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        process();
    }
    return 0;
}
