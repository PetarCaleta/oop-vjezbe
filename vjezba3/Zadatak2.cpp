#include <iostream>
#include <cstddef>
using namespace std;


template <typename T>
inline bool ascending(T a, T b) { return a < b; }

template <typename T>
inline bool descending(T a, T b) { return a > b; }

template <typename T>
void sort(T* niz, size_t dulj, bool (*cmp)(T, T)) {
	if (niz == 0) { return; }
	for (size_t i = 0; i < dulj; i++) {
		for (size_t j = i + 1; j < dulj; j++) {
			if (!cmp(niz[i], niz[j])) {
				T temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}


}

template <typename T>
void print(T* niz, size_t dulj) {
	for (size_t i = 0; i < dulj; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
}


int main() {
	int niz[] = { 6,2,4,1,9, 7 };
	double niz1[] = { 6.7, 6.5, 6.8, 6.1 };
	size_t dulj = sizeof(niz) / sizeof(niz[0]);
	size_t dulj1 = sizeof(niz1) / sizeof(niz1[0]);

	sort(niz, dulj, ascending);
	print(niz, dulj);
	sort(niz, dulj, descending);
	print(niz, dulj);


	sort(niz1, dulj1, ascending);
	print(niz1, dulj1);
	sort(niz1, dulj1, descending);
	print(niz1, dulj1);



	return 0;
}