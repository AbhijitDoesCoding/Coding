#include <bits/stdc++.h>

using namespace std;

class Knapsack
{
private:
    int B[20][20];
    int weights[20];
    int values[20];
    int n, W;

public:
    Knapsack(int n1, int w1, int weights1[], int values1[]) : n(n1), W(w1)
    {
        for (int i = 0; i < n; i++)
        {
            weights[i] = weights1[i];
            values[i] = values1[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                B[i][w] = 0; // Initialize B with zeros
            }
        }
    }

    Knapsack()
    {
        cout << "Enter the number of items: ";
        cin >> n;
        cout << "Enter the maximum weight capacity: ";
        cin >> W;

        cout << "Enter weights of items: ";
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }

        cout << "Enter values of items: ";
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                B[i][w] = 0;
            }
        }
    }

    void edit()
    {
        cout << "Enter the number of items: ";
        cin >> n;
        cout << "Enter the maximum weight capacity: ";
        cin >> W;

        cout << "Enter weights of items: ";
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }

        cout << "Enter values of items: ";
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                B[i][w] = 0;
            }
        }
    }

    int solve()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int w = 1; w <= W; w++)
            {
                if (weights[i - 1] <= w)
                {
                    B[i][w] = max(values[i - 1] + B[i - 1][w - weights[i - 1]], B[i - 1][w]);
                }
                else
                {
                    B[i][w] = B[i - 1][w];
                }
            }
        }
        showTable();
        return B[n][W];
    }

    void showTable()
    {
        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                cout << B[i][w] << "\t";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Knapsack knapsackSolver;
    int inp;
    int flag = 0;
    while (1)
    {
        cout << "--MENU--" << endl;
        cout << "1. Edit Knapsack\n2. Solve knapsack\n3. Exit" << endl;
        cin >> inp;
        switch (inp)
        {
        case 1:
            knapsackSolver.edit();
            break;
        case 2:
        {

            int max_value = knapsackSolver.solve();
            cout << "Maximum value that can be obtained: " << max_value << endl;
            break;
        }
        case 3:
            return 0;
        default:
            cout << "Invalid input." << endl;
        }
    }
    return 0;
}