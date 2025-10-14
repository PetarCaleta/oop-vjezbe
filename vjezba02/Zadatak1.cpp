/*

#include <iostream>

int *  fibonacci(int duzina) {

	int * rez = new  int[duzina]{1,1};

	for (int i = 2; i < duzina; i++) {
		rez[i] = rez[i - 2] + rez[i - 1];

	}
	return rez;
}


int main() {
	int n = 10;

	int * x = fibonacci(n);

	for (int i = 0; i < n; i++) {
		std::cout << x[i] << " ";
	}

	delete  x;
	x = nullptr;


	return 0;
}
*/