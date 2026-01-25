#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int minSwaps(vector<int>& A) {
    int n = A.size();
    vector<pair<int, int>> countSetBitsArray(n);
    
    // Count set bits for each element in A and store it along with the original element
    for (int i = 0; i < n; ++i) {
        countSetBitsArray[i] = {countSetBits(A[i]), A[i]};
    }

    // Sort the array based on the count of set bits
    sort(countSetBitsArray.begin(), countSetBitsArray.end());
    
    // Check if adjacent elements can be swapped
    int swaps = 0;
    for (int i = 1; i < n; ++i) {
        if (countSetBitsArray[i].first != countSetBitsArray[i - 1].first) {
            return -1; // Cannot swap, return -1
        }
        if (countSetBitsArray[i].second != countSetBitsArray[i - 1].second) {
            swaps++;
        }
    }
    
    return swaps;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << minSwaps(A) << endl;
    }
    return 0;
}
