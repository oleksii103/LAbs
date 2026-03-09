#include <iostream>
#include <algorithm>

int binary_search(const int arr[], int size, int key ) {
	int L = 0, R = size - 1;

	while (L <= R) {
		int M = L + (R -L)/ 2;
		if (key == arr[M]) {
			return M;
		}
		else if (key < arr[M]) {
			R = M - 1;
		}
		else L = M + 1;
	}

	return -1;
}

int main() {
	const int n = 10;
	int arr[n];

	std::srand(std::time(0));

	for (int i = 0; i < n; i++) {
		arr[i] = std::rand() % 100;
	}

	std::sort(arr, arr + n);
	std::cout << "sorted array: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << "; ";
	}

	std::cout << std::endl;

	int key;
	std::cout << "enter number you wanna search: "; std::cin >> key;

	int index = binary_search(arr, n, key);

	if (index != -1) {
		std::cout << "your element index: " << index << std::endl;
	}
	else std::cout << "we cant find your element :(";

	return 0;
}