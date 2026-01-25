#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solveExpression(string s) {
    ll lhsSum = 0, rhsSum = 0; // To store sums of constants
    int sign = 1; // To track the sign (+ or -)
    bool isRHS = false; // To check if we are on RHS of '='
    bool hasX = false; // To check if the current term is X

    ll num = 0;
    bool isNum = false;

    for (char c : s + '+') { // Add '+' at the end to handle the last term
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Construct the number
            isNum = true;
        } else if (c == 'X') {
            hasX = true; // Mark that this term is X
        } else {
            // If the current term is complete, process it
            if (isNum || hasX) {
                ll term = (hasX ? 0 : num) * sign; // Add the term value to sum
                if (isRHS) rhsSum += term;
                else lhsSum += term;

                if (hasX) { // Adjust X based on the side
                    if (isRHS) rhsSum -= sign;
                    else lhsSum -= sign;
                }
            }
            // Reset variables for the next term
            num = 0;
            isNum = hasX = false;

            // Adjust sign or switch to RHS
            if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '=') {
                isRHS = true;
                sign = 1;
            }
        }
    }

    return rhsSum - lhsSum; // Solve for X
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    cout << solveExpression(s) - 1 << "\n";

    return 0;
}
