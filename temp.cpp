#include <iostream>
#include <vector>
using namespace std;

template <class T>
void bubblesort(vector<T>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    while (1) {
        cout << "\nEnter the number of elements of the array: ";
        int n;
        cin >> n;

        cout << "\nWhat data type do you want to store in an array?\n1. Integer\n2. Float\n3. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                vector<int> arr(n);
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the " << i + 1 << "th element: ";
                    cin >> arr[i];
                }

                bubblesort(arr, n);

                cout << "\nThe sorted array:\n";
                for (int i = 0; i < n; i++) {
                    cout << "The " << i + 1 << "th element: " << arr[i] << endl;
                }
                break;
            }
            case 2: {
                vector<float> arr(n);
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter the " << i + 1 << "th element: ";
                    cin >> arr[i];
                }

                bubblesort(arr, n);

                cout << "\nThe sorted array:\n";
                for (int i = 0; i < n; i++) {
                    cout << "The " << i + 1 << "th element: " << arr[i] << endl;
                }
                break;
            }
            case 3:
                exit(0);
            default:
                cout << "\nInvalid choice.";
        }
    }
    return 0;
}
