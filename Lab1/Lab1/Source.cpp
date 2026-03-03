#include <iostream>
#include <cmath>
int main() {
	int chs;
	std::cout << "chose task 1/2: "; std::cin >> chs;
	switch (chs) {
	case 1: {
		//task 1.1
		float c1, c2, c3, a, x, z;
		std::cout << "enter x: "; std::cin >> x;
		std::cout << "enter z: "; std::cin >> z;
		if (z > 0) {
			c1 = exp(pow(x, 2));
			c2 = log(z) / pow(2, x);
			c3 = pow(tan(c2), 2);
			a = c1 + c2;

			std::cout << "resut: " << a << std::endl;
		}
		else {
			std::cout << "eror" << std::endl;
		}
		break;
	}
	case 2: {
		//task 1.2
		float a, b;
		float c, S, P;
		std::cout << "enter side a: "; std::cin >> a;
		std::cout << "enter side b: "; std::cin >> b;
		S = (a * b) / 2;
		c = sqrt(pow(a, 2) + pow(b, 2));
		P = a + b + c;
		std::cout << "area: " << S << std::endl;
		std::cout << "perimeter: " << P << std::endl;
		break;
	}
	default:
		//error
		std::cout << "no no no mr. fish you can`t do this";
	}
	return 0;
}