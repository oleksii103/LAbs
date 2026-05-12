#include <iostream>
#include <algorithm>

double arithmeticLinear(double a1, double d, int n) {
    if (n == 1)
        return a1;

    return arithmeticLinear(a1, d, n - 1) + d;
}

double arithmeticTail(double current, double d, int n) {
    if (n == 1)
        return current;

    return arithmeticTail(current + d, d, n - 1);
}

double geometricLinear(double a1, double q, int n) {
    if (n == 1)
        return a1;

    return geometricLinear(a1, q, n - 1) * q;
}

double geometricTail(double current, double q, int n) {
    if (n == 1)
        return current;

    return geometricTail(current * q, q, n - 1);
}

void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double* L = new double[n1];
    double* R = new double[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

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
    double a1, d, q;

    std::cout << "Enter N (100 < N < 1000): ";
    std::cin >> N;

    if (N <= 100 || N >= 1000) {
        std::cout << "Invalid N\n";
        return 1;
    }

    std::cout << "Enter first element a1: ";
    std::cin >> a1;

    std::cout << "Enter difference d: ";
    std::cin >> d;

    std::cout << "Enter ratio q: ";
    std::cin >> q;

    double* arr = new double[N];

    std::cout << "\nArithmetic progression (linear recursion):\n";

    for (int i = 0; i < N; i++) {
        arr[i] = arithmeticLinear(a1, d, i + 1);
        std::cout << arr[i] << " ";
    }

    std::cout << "\n\nArithmetic progression (tail recursion):\n";

    for (int i = 0; i < N; i++) {
        arr[i] = arithmeticTail(a1, d, i + 1);
        std::cout << arr[i] << " ";
    }

    std::cout << "\n\nGeometric progression (linear recursion):\n";

    for (int i = 0; i < N; i++) {
        arr[i] = geometricLinear(a1, q, i + 1);
        std::cout << arr[i] << " ";
    }

    std::cout << "\n\nGeometric progression (tail recursion):\n";

    for (int i = 0; i < N; i++) {
        arr[i] = geometricTail(a1, q, i + 1);
        std::cout << arr[i] << " ";
    }

    mergeSort(arr, 0, N - 1);

    std::cout << "\n\nSorted array (merge sort):\n";

    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}