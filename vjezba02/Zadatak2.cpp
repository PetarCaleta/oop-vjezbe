#include <iostream>

typedef struct {
	int *niz;
	int logicka, fizicka;

	

}vektor;

vektor vector_new(int n) {
	vektor rezultat;
	
	rezultat.fizicka = n;
	rezultat.logicka = 0;
	rezultat.niz= new int [n]{};

	
	return rezultat;
}

void vector_delete(vektor za_brisat) {

}




int main() {
	



	return 0;
}