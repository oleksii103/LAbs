#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
	const int n = 10;
	int arr[n], arr2[n], minIndex, maxIndex, minIndex2, maxIndex2;
	int* maxElem;
	int* minElem;
	int* maxElem2;
	int* minElem2;

	//task 2
	std::cout << "enter your array (by height): " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> arr2[i];
	}

	system("cls");
	
	std::cout << "your array: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr2[i] << "; ";
	}

	maxElem2 = std::max_element(arr2, arr2 + n);
	minElem2 = std::min_element(arr2, arr2 + n);

	for (int i = 0; i < n; i++) {
		if (arr2[i] == *maxElem2) {
			maxIndex2 = i;
		}
		else if (arr2[i] == *minElem2) {
			minIndex2 = i;
		}
	}

	std::cout << "\nmaximum element and his index: " << *maxElem2 << "/" << maxIndex2 << std::endl;
	std::cout << "minimum element and his index: " << *minElem2 << "/" << minIndex2 << std::endl;

	std::cout << std::endl;
	//task 1
 	std::cout << "\nour array: " << std::endl;
	for (int i = 0; i < n; i++) {
		arr[i] = (pow(i, 2) + 2) * sin(pow(i, 2));
		std::cout << arr[i] << "; ";
	}

	maxElem = std::max_element(arr, arr + n);
	minElem = std::min_element(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] == *maxElem) {
			maxIndex = i;
		}
		else if (arr[i] == *minElem) {
			minIndex = i;
		}
	}

	std::cout << "\nmaximum element and his index: " << *maxElem << "/" << maxIndex << std::endl;
	std::cout << "minimum element and his index: " << *minElem << "/" << minIndex << std::endl;

	return 0;
}