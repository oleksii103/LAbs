#include <iostream>
#include <algorithm> 

int main() {
    const int N = 6;
    int C[N][N];

    std::cout << "Enter elements of matrix 6x6:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> C[i][j];
        }
    }

    int diag[N];
    for (int i = 0; i < N; i++) {
        diag[i] = C[i][i];
    }

    std::sort(diag, diag + N, std::greater<int>());

    for (int i = 0; i < N; i++) {
        C[i][i] = diag[i];
    }

    std::cout << "\nMatrix after sorting main diagonal (descending):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}