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
#define inf 1e18
#define PI 3.1415926535897932384626
#define loop(i, l, h) for (int i = l; i < h; i++)
#define rev(i, l, h) for (int i = h - 1; i >= l; i--)
ll binpow(ll b, ll p, ll mod1) {
    ll ans = 1;
    b %= mod1;
    for (; p; p >>= 1) {
        if (p & 1) ans = ans * b % mod1;
        b = b * b % mod1;
    }
    return ans;
}

const int U = 1 << 30;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    pair<int, int> cur = intervals[0];
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= cur.second) {
            cur.second = max(cur.second, intervals[i].second);
        } else {
            merged.push_back(cur);
            cur = intervals[i];
        }
    }
    merged.push_back(cur);
    return merged;
}

vector<pair<int, int>> splitInterval(int L, int R) {
    vector<pair<int, int>> blocks;
    while (L < R) {
        int step = (L == 0 ? 1 : L & -L);
        while ((long long)step << 1 <= R - L)
            step <<= 1;
        while (L + step > R)
            step >>= 1;
        blocks.push_back({L, L + step});
        L += step;
    }
    return blocks;
}

vector<pair<int, int>> imageOfInterval(int c, int L, int R) {
    vector<pair<int, int>> blocks = splitInterval(L, R);
    vector<pair<int, int>> images;
    for (auto &b : blocks) {
        int a = b.first, bEnd = b.second;
        int size = bEnd - a;
        int k = 31 - __builtin_clz(size);
        int C = c >> k;
        int newA = (a / size) ^ C;
        int blockStart = newA * size;
        int blockEnd = blockStart + size;
        images.push_back({blockStart, blockEnd});
    }
    return mergeIntervals(images);
}

vector<pair<int, int>> complementIntervals(const vector<pair<int, int>> &intervals, int U) {
    vector<pair<int, int>> comp;
    int prev = 0;
    for (auto &iv : intervals) {
        if (prev < iv.first)
            comp.push_back({prev, iv.first});
        prev = max(prev, iv.second);
    }
    if (prev < U)
        comp.push_back({prev, U});
    return comp;
}

vector<pair<int, int>> getIntervalXor(int c, int L, int U) {
    vector<pair<int, int>> img = imageOfInterval(c, 0, L);
    vector<pair<int, int>> comp = complementIntervals(img, U);
    return mergeIntervals(comp);
}

vector<pair<int, int>> intersectIntervals(const vector<pair<int, int>> &A, const vector<pair<int, int>> &B) {
    vector<pair<int, int>> res;
    int i = 0, j = 0;
    while (i < (int)A.size() && j < (int)B.size()) {
        int L = max(A[i].first, B[j].first);
        int R = min(A[i].second, B[j].second);
        if (L < R)
            res.push_back({L, R});
        if (A[i].second < B[j].second)
            i++;
        else
            j++;
    }
    return res;
}

bool inIntervals(const vector<pair<int, int>> &intervals, int x) {
    int lo = 0, hi = intervals.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (intervals[mid].first <= x && x < intervals[mid].second)
            return true;
        else if (x < intervals[mid].first)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return false;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        S[i] = A[n - 1 - i];
    }

    vector<int> T(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        T[i] = T[i - 1] ^ S[i - 1];
    }

    vector<vector<pair<int, int>>> IIntervals(n);
    for (int i = 0; i < n; i++) {
        IIntervals[i] = mergeIntervals(getIntervalXor(T[i], S[i], U));
    }

    vector<vector<pair<int, int>>> JIntervals(n + 1);
    JIntervals[0].push_back({0, U});
    int maxValid = 0;
    for (int k = 0; k < n; k++) {
        vector<pair<int, int>> inter = intersectIntervals(JIntervals[k], IIntervals[k]);
        inter = mergeIntervals(inter);
        JIntervals[k + 1] = inter;
        if (inter.empty()) {
            maxValid = k;
            for (int kk = k + 1; kk <= n; kk++) {
                JIntervals[kk].clear();
            }
            break;
        } else {
            maxValid = k + 1;
        }
    }

    for (int i = 0; i < q; i++) {
        int z;
        cin >> z;
        int lo = 0, hi = maxValid;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (!JIntervals[mid].empty() && inIntervals(JIntervals[mid], z))
                lo = mid;
            else
                hi = mid - 1;
        }
        cout << lo << (i + 1 == q ? "\n" : " ");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
