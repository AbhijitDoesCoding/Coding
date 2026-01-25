#include <iostream>
#include <vector>

using namespace std;

// Define the size of the matrix (2x2)
#define K 2

// Typedef for a 2x2 matrix
typedef vector<vector<long long>> Matrix;

// Function to multiply two 2x2 matrices (A * B)
Matrix multiply(const Matrix& A, const Matrix& B, long long M) {
    Matrix C(K, vector<long long>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < K; k++) {
                // Ensure all intermediate products are taken modulo M
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }
    return C;
}

// Function to calculate Matrix A raised to the power p (A^p)
Matrix power(Matrix A, long long p, long long M) {
    // Base case: Identity matrix for p=0
    Matrix res(K, vector<long long>(K));
    res[0][0] = res[1][1] = 1;
    
    // Binary exponentiation (Exponentiation by Squaring)
    while (p > 0) {
        if (p & 1) { // If p is odd
            res = multiply(res, A, M);
        }
        A = multiply(A, A, M); // Square the matrix A
        p >>= 1; // Divide p by 2
    }
    return res;
}

/**
 * Calculates the n-th Fibonacci number (F_n) modulo M.
 * Time Complexity: O(log n)
 */
long long fibonacci_matrix(long long n, long long M) {
    if (n <= 1) return n;

    // The base transformation matrix
    Matrix T(K, vector<long long>(K));
    T[0][0] = 1; T[0][1] = 1;
    T[1][0] = 1; T[1][1] = 0;

    // Calculate T^(n-1)
    Matrix Tn = power(T, n - 1, M);
    
    // F_n is the result of multiplying Tn with the base vector {F_1, F_0} = {1, 0}
    // F_n = Tn[0][0] * F_1 + Tn[0][1] * F_0 
    // F_n = Tn[0][0] * 1 + Tn[0][1] * 0 
    return Tn[0][0];
}

// Example usage:
/*
int main() {
    long long n = 10;
    long long M = 1000000007; // Standard modulo
    cout << "F(" << n << ") mod " << M << " = " << fibonacci_matrix(n, M) << endl; // F(10) = 55
    
    n = 1000000000000000000LL; // 10^18
    cout << "F(" << n << ") mod " << M << " = " << fibonacci_matrix(n, M) << endl; // Calculates quickly
    return 0;
}
*/