#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nline cout << "\n";
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define e 2.718281828459045235360
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i, l, h) for (int i = l; i < h; i++)
#define rev(i, l, h) for (int i = h - 1; i >= l; i--)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

struct Circle {
    int cx, cy, r;
};

bool is_inside_circle(int x, int y, const Circle& circle) {
    double dist_squared = (x - circle.cx) * (x - circle.cx) + (y - circle.cy) * (y - circle.cy);
    return dist_squared < (circle.r * circle.r);
}

bool can_reach_destination(int X, int Y, const vector<Circle>& circles) {
    if (is_inside_circle(0, 0, circles[0]) || is_inside_circle(X, Y, circles[0])) {
        return false;
    }

    queue<pi> q;
    vector<vector<bool>> visited(X + 1, vector<bool>(Y + 1, false));
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == X && y == Y) {
            return true;
        }

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) == abs(dy)) continue;

                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx > X || ny > Y || visited[nx][ny]) {
                    continue;
                }

                bool inside_any_circle = false;
                for (const auto& circle : circles) {
                    if (is_inside_circle(nx, ny, circle)) {
                        inside_any_circle = true;
                        break;
                    }
                }

                if (!inside_any_circle) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

void solve() {
    int X, Y;
    cin >> X >> Y;

    int N;
    cin >> N;

    vector<Circle> circles(N);
    for (int i = 0; i < N; ++i) {
        cin >> circles[i].cx >> circles[i].cy >> circles[i].r;
    }

    if (can_reach_destination(X, Y, circles)) {
        yes
    } else {
        no
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
