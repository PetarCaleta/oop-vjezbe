
#include <iostream>
using namespace std;

int main() {

	
	auto paran = [](int x) {return x % 2 == 0; };
	auto neparan = [](int x) {return x % 2 != 0; };
	
	int sum = 0;
	int prod = 1;
	auto zbroj = [&sum](int x) {return sum += x; };
	auto produkt = [&prod](int x) {return prod *= x; };

	cout << "jeli paran: " << paran(4) << endl;
	cout << "jeli neparan: " << neparan(5) << endl;
	cout << "suma: " << zbroj(6) << endl;
	cout << "produkt: " << produkt(5) << endl;
	
	int niz[] = { 1,2,4,5,6 };
	int dulj = sizeof(niz) / sizeof(niz[0]);

	sum = 0;
	int prag = 4;

	auto  threshold= [prag, &sum](int x) {
		if (x > prag) sum += x; };

	for (int i = 0; i < dulj; i++) {
		threshold(niz[i]);
	}
	cout << "Suma brojeva vecih od " << prag << " je: " << sum << endl;

	auto par_nepar = [&](int* niz, int dulj) {
		for (int i = 0; i < dulj; i++) {
			if (paran(niz[i])) {
				niz[i] /= 2;
			}
			else {
				niz[i] *= 2;
			}
		}
		};
	par_nepar(niz, dulj);
	cout << "nakon transformacije: ";
	for (int i = 0; i < dulj; i++) {
		cout << " " << niz[i];

	}
	cout << endl;
	
	auto sum_produkt = [&](int* niz, int dulj) {
		sum = 0, prod = 1;
		for (int i = 0; i < dulj; i++) {
			zbroj(niz[i]);
			produkt(niz[i]);
		}
		cout << "suma niza: " << sum << endl;
		cout << "produkt niza: " << prod << endl;
		};

	sum_produkt(niz, dulj);

	prag = 3;
	int niz1[] = { 1,2,4,5,6 };
	auto prag_suma = [prag, &sum](int* niz, int dulj) {
		sum = 0;

		for (int i = 0; i < dulj; i++) {
			if (niz[i] > prag) sum += niz[i];
		}
		cout << "suma brojeva povise praga: " << sum << endl;
	};

	prag_suma(niz1, dulj);

	return 0;
}
