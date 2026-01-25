#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
const int mod = 1000000007;

// Inline modular arithmetic functions.
inline void add(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
    a -= b;
    if(a < 0) a += mod;
}

inline int mul(int a, int b) {
    return (int)(((long long)a * b) % mod);
}

inline int power(int a, long long b) {
    int res = 1;
    while(b) {
        if(b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a) {
    return power(a, mod - 2);
}

// Data structure to maintain running statistics.
struct Data {
    int sum, cnt;  // For mean: sum (mod mod) and count.
    
    // For median, we use two multisets:
    multiset<int> low, high;
    
    // For mode, we use a frequency map and a multiset of (frequency, value) pairs.
    unordered_map<int, int> freq;
    multiset<pair<int, int>> freqset;  // Stored in increasing order: (frequency, value)
    
    Data() : sum(0), cnt(0) {}
    
    // Balances the two multisets so that:
    //   - low.size() == high.size()  (even number of elements)
    //   - or low.size() == high.size() + 1  (odd number of elements)
    void balance() {
        while(low.size() > high.size() + 1) {
            int x = *low.rbegin();
            low.erase(low.find(x));
            high.insert(x);
        }
        while(high.size() > low.size()){
            int x = *high.begin();
            high.erase(high.begin());
            low.insert(x);
        }
    }
    
    void insert(int x) {
        // Update mean (do addition modulo mod)
        sum = (sum + x) % mod;
        cnt++;
        
        // Update mode:
        freq[x]++;
        int f = freq[x];
        freqset.insert({f, x});
        // Remove the outdated pair for this value.
        if(freqset.find({f - 1, x}) != freqset.end()){
            freqset.erase(freqset.find({f - 1, x}));
        }
        
        // Update median:
        if(low.empty() || x <= *low.rbegin()){
            low.insert(x);
        } else {
            high.insert(x);
        }
        balance();
    }
    
    void remove(int x) {
        // Update mode:
        int f = freq[x];
        auto it = freqset.find({f, x});
        if(it != freqset.end()) {
            freqset.erase(it);
        }
        
        // Update mean:
        sum = ((sum - x) % mod + mod) % mod;
        cnt--;
        
        // Update frequency:
        freq[x]--;
        if(freq[x] > 0) {
            freqset.insert({freq[x], x});
        }
        
        // Update median: remove x from the correct multiset.
        auto itLow = low.find(x);
        if(itLow != low.end()){
            low.erase(itLow);
        } else {
            auto itHigh = high.find(x);
            if(itHigh != high.end())
                high.erase(itHigh);
        }
        balance();
    }
    
    // Returns the mean as (sum * inv(cnt)) mod mod.
    int getMean() {
        if(cnt == 0) return -1;
        return mul(sum, inv(cnt));
    }
    
    // Returns the mode. If multiple values share the highest frequency, the smallest is chosen.
    int getMode() {
        if(freqset.empty()) return -1;
        // The last element in freqset has the maximum frequency.
        auto it = freqset.rbegin();
        int max_freq = it->first;
        int mode_val = it->second;
        // Iterate over all pairs with frequency equal to max_freq.
        // Note: lower_bound/upper_bound on multiset<pair<int,int>> works as expected.
        for(auto itr = freqset.lower_bound({max_freq, INT_MIN}); 
            itr != freqset.upper_bound({max_freq, INT_MAX}); ++itr) {
            mode_val = min(mode_val, itr->second);
        }
        return mode_val;
    }
    
    // Returns the median. For even number of elements, we compute (a+b)/2 modulo mod
    // using modular inverse of 2.
    int getMedian() {
        if(cnt == 0) return -1;
        balance();
        if(low.size() == high.size()){
            int a = *low.rbegin();
            int b = *high.begin();
            int sum_ab = ((a + b) % mod + mod) % mod;
            return mul(sum_ab, inv(2));
        } else {
            return *low.rbegin() % mod;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        Data d;
        while(q--){
            string op;
            cin >> op;
            if(op == "insert"){
                int x;
                cin >> x;
                d.insert(x);
            } else if(op == "remove"){
                int x;
                cin >> x;
                d.remove(x);
            } else if(op == "getMean"){
                cout << d.getMean() << "\n";
            } else if(op == "getMode"){
                cout << d.getMode() << "\n";
            } else if(op == "getMedian"){
                cout << d.getMedian() << "\n";
            }
        }
    }
    return 0;
}
