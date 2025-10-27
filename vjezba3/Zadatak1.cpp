#include <iostream>
#include <cstddef>
using namespace std;

inline bool ascending(int a, int b) { return a < b; }
inline bool descending(int a, int b) { return a > b; }

void sort(int* niz, size_t dulj, bool (*cmp)(int, int)) {
	if (niz == 0) { return; }
	for (size_t i = 0; i < dulj; i++) {
		for (size_t j = i + 1; j < dulj; j++) {
			if (!cmp(niz[i], niz[j])) {
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}


}
void print(int* niz, size_t dulj) {
	for (size_t i = 0; i < dulj; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
}



int main() {
	int niz[] = { 6,2,4,1,9, 7 };
	size_t dulj = sizeof(niz) / sizeof(niz[0]);

	sort(niz, dulj, ascending);
	print(niz, dulj);
	sort(niz, dulj, descending);
	print(niz, dulj);


		
	return 0;
}