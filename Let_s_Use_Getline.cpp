#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    getline(cin, s); 
    size_t pos = s.find('\\');
    
    cout << s.substr(0, pos) << "\n";
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve(); // Call the solve function
    return 0;
}
