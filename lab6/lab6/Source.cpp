#include <iostream>
#include <ctime>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortDesc(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    const int N = 6;
    int C[N][N];

    srand(time(0));

    cout << "Matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = rand() % 100;
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    int diag[N];
    for (int i = 0; i < N; i++) {
        diag[i] = C[i][i];
    }

    heapSortDesc(diag, N);

    for (int i = 0; i < N; i++) {
        C[i][i] = diag[i];
    }

    cout << "\nSorted matrix (main diagonal desc):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}