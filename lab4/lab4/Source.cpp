#include <iostream>
#include <cmath>

using namespace std;

double getA(double x) {
    if (x < 0.5) return 0.1;
    else if (x <= 1) return 0.5;
    else return 1.0;
}

double calcY(double x, double b) {
    double a = getA(x);
    return (pow(a, x) + pow(b, -x)) / (pow(sin(b * x), 2) + 1.24);
}

void bubbleSort(double arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void insertionSort(double arr[], int n, int& comp, int& swaps) {
    comp = swaps = 0;

    for (int i = 1; i < n; i++) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && (++comp && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
}

int main() {
    double b = 0.15;
    double x_start = 0.1, x_end = 2.6, step = 0.1;

    int n = (x_end - x_start) / step + 1;
    double* y = new double [n];

    cout << "Table:\n";
    int i = 0;
    for (double x = x_start; x <= x_end + 1e-9; x += step) {
        y[i] = calcY(x, b);
        cout << "x=" << x << " | " << "\ty=" << y[i] << endl;
        i++;
    }

    double*   y1 = new double [n];
    double* y2 = new double[n];
    for (int i = 0; i < n; i++) {
        y1[i] = y[i];
        y2[i] = y[i];
    }

    int comp1, swap1, comp2, swap2;

    bubbleSort(y1, n, comp1, swap1);
    cout << "\nBubble sorted:\n";
    for (int i = 0; i < n; i++) cout << y1[i] << " ";
    cout << "\nComparisons: " << comp1 << " Swaps: " << swap1 << endl;
    
    insertionSort(y2, n, comp2, swap2);
    cout << "\nInsertion sorted:\n";
    for (int i = 0; i < n; i++) cout << y2[i] << " ";
    cout << "\nComparisons: " << comp2 << " Swaps: " << swap2 << endl;

    return 0;
}