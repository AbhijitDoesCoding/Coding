#include <iostream>
#include <vector>
using namespace std;
const int M = 1000002;
vector<int> p;
vector<int> sppf(M, 0);
void calculate_smallest_prime_factors() {
    sppf[1] = 1;
    for (int i = 2; i < M; ++i) {
        if (sppf[i] == 0) {
            sppf[i] = i;
            for (long long j = (long long)i * i; j < M; j += i) {
                if (sppf[j] == 0) {
                    sppf[j] = i;}
            }  } }
}
void compute_result_for_k() {
    int k;
    cin >> k;
    long long res = 0;
    if (sppf[k] == k) {
        for (int prime : p) {
            if (prime > k) break;
            res += (long long)prime * k;
        }
    } else {
        for (int prime : p) {
            if (prime > sppf[k]) break;
            res += (long long)prime * k;
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    calculate_smallest_prime_factors();
    
    for (int i = 2; i < M; ++i) {
        if (sppf[i] == i) {
            p.push_back(i);
        }
    }
    int HA;
    cin >> HA;
    for (int i = 0; i < HA; ++i) {
        compute_result_for_k();
    }
    return 0;
}
