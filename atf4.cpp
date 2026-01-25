#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate
using namespace std;

// Function to calculate how many people are needed to ensure that
// no group of pieces has a total weight smaller than `minShare`
int numberOfPeopleNeeded(const vector<int>& a, int minShare) {
    int currentSum = 0, people = 1; // Start with one person
    
    for (int weight : a) {
        if (currentSum + weight > minShare) {
            people++;        // Start a new group
            currentSum = weight; // This piece starts the new group
        } else {
            currentSum += weight; // Add this piece to the current group
        }
    }
    
    return people;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Binary search for the answer
    int left = *max_element(a.begin(), a.end()); // Minimum possible minShare is the largest piece
    int right = accumulate(a.begin(), a.end(), 0); // Maximum possible minShare is the sum of all pieces
    
    int result = left; // We want to maximize the minimum share
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // Calculate how many people we need if the minimum share is `mid`
        int peopleNeeded = numberOfPeopleNeeded(a, mid);
        
        if (peopleNeeded <= k) {
            // If the number of people needed is less than or equal to `k`, this `mid` is valid
            result = mid; // Update result to this value of mid
            left = mid + 1; // Try for a larger minimum share
        } else {
            right = mid - 1; // This `mid` is too large, try a smaller value
        }
    }
    
    cout << result << endl;
    
    return 0;
}
// unable to resolve configuaration with compilerpath "c:\MinGw"