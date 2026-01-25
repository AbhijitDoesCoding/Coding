#include <iostream>  // For input/output operations (cin, cout)
#include <vector>     // For dynamic arrays (vector)
#include <set>        // For storing unique elements (set)
#include <algorithm>  // For sorting and searching algorithms (find, erase)
#include <cmath>       // Not used in this code, but included for potential future use

using namespace std;

// Define convenient type aliases for readability
typedef long long int_type;
typedef pair<int_type, int_type> int_pair;
typedef vector<int_pair> int_pair_vector;
typedef vector<int_type> int_vector;
typedef vector<int_vector> int_matrix;

void solve() {
  // Input number of elements (n)
  int_type n;
  cin >> n;

  // Create vectors to store elements of arrays A and B
  int_vector a(n);
  int_vector b(n);

  // Read elements of array A
  for (int_type i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // Create a set to store unique elements of array B for faster lookups
  set<int_type> b_set;
  for (int_type i = 0; i < n; ++i) {
    cin >> b[i];
    b_set.insert(b[i]);  // Insert elements of B into the set
  }

  // Create a multiset to store elements in B that are not yet found in A
  // (represents requirements to be fulfilled)
  multiset<int_type> requirements;
  for (int_type i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      requirements.insert(b[i]);  // Insert required elements
    }
  }

  // Input number of operations (m)
  int_type m;
  cin >> m;

  // Flag to track if all requirements are met and the last operation is successful
  bool all_done = false;

  // Process each operation
  for (int_type i = 0; i < m; ++i) {
    int_type x;
    cin >> x;

    // Check if the operation fulfills a requirement
    if (requirements.find(x) != requirements.end()) {
      requirements.erase(requirements.find(x));  // Remove fulfilled requirement

      // If this is the last operation, set the flag if requirements are met
      if (i == m - 1) {
        all_done = requirements.empty();  // Check if all requirements are gone
      }
    } else if (b_set.count(x) > 0) {
      // If the element is present in B but not yet a requirement,
      // it can potentially fulfill a requirement later, so consider it successful
      // for the last operation
      if (i == m - 1) {
        all_done = true;
      }
    }
  }

  // Print YES if all requirements are met and the last operation is successful
  if (all_done) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  // Improve input/output efficiency (optional)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Input number of test cases
  int total_tests;
  cin >> total_tests;

  // Run solve() for each test case
  for (int test_no = 1; test_no <= total_tests; test_no++) {
    solve();
  }

  return 0;
}
