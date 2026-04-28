#include <iostream>
#include <algorithm>

using namespace std;

void merge (double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    double a1, d;

    cout << "Enter N (100 < N < 1000): ";
    cin >> N;

    if (N <= 100 || N >= 1000) {
        cout << "Invalid N\n";
        return 1;
    }

    cout << "Enter a1: ";
    cin >> a1;

    cout << "Enter d: ";
    cin >> d;

    double* arr = new double[N];

    for (int i = 0; i < N; i++) {
        arr[i] = a1 + d * i;
    }

    cout << "\nArray:\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    sort(arr, arr + N);

    cout << "\n\nSorted (std::sort):\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    mergeSort((double*)arr, 0, N - 1);

    cout << "\n\nSorted (merge sort):\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    double Sn = (N * (2 * a1 + d * (N - 1))) / 2;

    cout << "\n\nSum = " << Sn << endl;

    delete[] arr;
    return 0;
}