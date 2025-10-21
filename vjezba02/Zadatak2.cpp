#include <iostream>
using namespace std;

typedef struct {
	int* niz;
	int logicka;
	int fizicka;



}vektor;

vektor* vector_new(int kapacitet) {
	vektor* v = new vektor;
	v->niz = new int[kapacitet];
	v->logicka = 0;
	v->fizicka = kapacitet;
	return v;
}

void vector_delete(vektor* v) {
	delete[] v->niz;
	delete v;
}

void vector_push_back(vektor* v, int vrijednsot) {
	if (v->logicka >= v->fizicka) {
		v->fizicka *= 2;
		int* novi = new int[v->fizicka];
		for (int i = 0; i < v->logicka; i++) {
			novi[i] = v->niz[i];
		}
		delete[] v->niz;
		v->niz = novi;
	}
	v->niz[v->logicka] = vrijednsot;
	v->logicka++;
}
void vector_pop_back(vektor* v) {
	if (v->logicka > 0) {
		v->logicka--;
	}
	else {
		cout << "Vektor je prazan" << endl;
	}
	
}

int vector_front(vektor* v) {
	if (v->logicka > 0) {
		return v->niz[0];
	}
	else {
		cout << "Vektor je prazan" << endl;
		return 0;
	}

}

int vector_back(vektor* v) {
	if (v->logicka > 0) {
		return v->niz[v->logicka - 1];
	}
	else {
		cout << "Vektor je prazan" << endl;
		return 0;
	}
}

int vector_size(vektor* v) {
	return v->logicka;
}



int main() {
	
	vektor* v = vector_new(2);

	vector_push_back(v, 10);
	vector_push_back(v, 20);
	vector_push_back(v, 30);

	cout << "prvi element:" << vector_front(v) << endl;
	cout << "zadnji element:" << vector_back(v) << endl;
	cout << "velicina:" << vector_size(v) << endl;
	cout << "kapacitet:" << v->fizicka << endl;

	vector_pop_back(v);
	cout << "velicina nakon pop_back:"<< vector_size(v) << endl;

	vector_delete(v);



	return 0;
}
