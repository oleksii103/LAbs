#include <iostream>
#include <algorithm> 
#include <ctime>


void shell(int arr[], int N ) {
    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i++) {
            int t = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < t; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = t;
        }

    }
}

int main() {
    const int N = 6;
    int C[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = rand() % 100;
        }
    }


    int diag[N];
    for (int i = 0; i < N; i++) {
        diag[i] = C[i][i];
    }

    shell(diag, N);

    for (int i = 0; i < N; i++) {
        C[i][i] = diag[i];
    }

    std::cout << "\nMatrix after sorting main diagonal:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}