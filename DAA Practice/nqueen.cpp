#include <bits/stdc++.h>
using namespace std;

class nqueen
{
private:
    int n;
    int board[12];
    int solutionCount = 0;

    bool place(int k, int i)
    {
        for (int j = 0; j < k; j++)
        {
            if (board[j] == i || abs(board[j] - i) == abs(j - k))
            {
                return false;
            }
        }
        return true;
    }

    void printBoard()
    {
        cout << "Solution " << solutionCount << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void recursiveSolve(int k)
    {
        if (k == n)
        {
            solutionCount++;
            printBoard();
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (place(k, i))
            {
                board[k] = i;
                recursiveSolve(k + 1);
            }
        }
    }

public:
    nqueen(int size) : n(size)
    {
        for (int i = 0; i < n; i++)
        {
            board[i] = -1;
        }
    }

    void setN(int size)
    {
        n = size;
        if (size > 12)
        {
            cout << "Size exceeds maximum limit of 12.\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            board[i] = -1;
        }
    }

    void solve()
    {
        recursiveSolve(0);
        cout << "Total solutions: " << solutionCount << "\n";
    }

    void solveItr()
    {
        int k = 0;
        board[k] = -1;
        solutionCount = 0;
        while (k >= 0)
        {
            board[k]++;
            while (board[k] < n && !place(k, board[k]))
            {
                board[k]++;
            }
            if (board[k] < n)
            {
                if (k == n - 1)
                {
                    solutionCount++;
                    printBoard();
                }
                else
                {
                    k++;
                    board[k] = -1;
                }
            }
            else
            {
                k--;
            }
        }
        cout << "Total solutions: " << solutionCount << "\n";
    }
};

int main()
{
    int n;
    cout << "Enter the size of the board (n <= 12): ";
    cin >> n;
    while (1)
    {
        cout << "1. Solve using recursion\n2. Solve using iteration\n3. Set number of queens\n4. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;
        nqueen nq(n);
        switch (choice)
        {
        case 1:
            nq.solve();
            break;
        case 2:
            nq.solveItr();
            break;
        case 3:
            cout << "Enter new size of the board (n <= 12): ";
            cin >> n;
            nq.setN(n);
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
        cout << "Do you want to continue? (y/n): ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N')
        {
            cout << "Exiting...\n";
            break;
        }
        cout << "\n";
    }
    return 0;
}