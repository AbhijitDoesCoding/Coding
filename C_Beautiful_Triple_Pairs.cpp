#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TripleHash {
    size_t operator()(const array<int, 3>& triple) const {
        return triple[0] ^ (triple[1] << 16) ^ (triple[2] << 32);
    }
};

struct TripleEqual {
    bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
    }
};

long long count_beautiful_pairs(vector<int>& a) {
    unordered_map<array<int, 3>, int, TripleHash, TripleEqual> count;
    long long result = 0;
    int left = 0;
    int right = 2;
    while (right < a.size()) {
        array<int, 3> triple = {a[left], a[left+1], a[left+2]};
        count[triple]++;
        while (right - left >= 3) {
            for (int i = left + 1; i <= right - 2; i++) {
                array<int, 3> other = {a[i], a[i+1], a[i+2]};
                if ((triple[0] != other[0] && triple[1] == other[1] && triple[2] == other[2]) ||
                    (triple[0] == other[0] && triple[1] != other[1] && triple[2] == other[2]) ||
                    (triple[0] == other[0] && triple[1] == other[1] && triple[2] != other[2])) {
                    result += count[other];
                }
            }
            count[array<int, 3>{a[left], a[left+1], a[left+2]}]--;
            left++;
        }
        right++;
    }
    return result / 2;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << count_beautiful_pairs(a) << endl;
    }
    return 0;
}