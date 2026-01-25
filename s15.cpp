#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

char findBestBrand(int N, const string& candies) {
    unordered_set<char> smallCandies, largeCandies;
    
    // Iterate through the candies and populate sets of small and large candies
    for (char candy : candies) {
        if (islower(candy)) {
            smallCandies.insert(candy);
        } else {
            largeCandies.insert(tolower(candy));
        }
    }
    
    // Find the intersection of sets to get brands with both small and large candies
    vector<char> brands;
    for (char brand : smallCandies) {
        if (largeCandies.count(brand) > 0) {
            brands.push_back(brand);
        }
    }
    
    // If no such brand exists, return 0
    if (brands.empty()) {
        return '0';
    }
    
    // Find the best brand among brands with both small and large candies
    sort(brands.begin(), brands.end());
    return toupper(brands.back());
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        string candies;
        cin >> candies;
        
        cout << findBestBrand(N, candies) << endl;
    }
    
    return 0;
}
