#include <iostream>
#include <string>
using namespace std;

typedef struct {
	string ime;
	string JMBAG;
	int godina;
	int ECTS;
	double prosjek;

}student;

void filter(student studenti[], size_t dulj, void (*akcija)(student&), bool (*filter)(student&)) {
	for (size_t i = 0; i < dulj; i++) {
		if (filter(studenti[i])) {
			akcija(studenti[i]);
		}
	}
}
void ispis(student& s) {
	cout << "Ime: " << s.ime
		<< " JMBAG: " << s.JMBAG
		<< " Godina studija: " << s.godina
		<< " Broj ECTS bodova: " << s.ECTS
		<< " Prosjek ocjena: " << s.prosjek
		<< endl;
}

void povecaj(student& s) {
	++s.godina;
}


int main() {
	student studenti[] = {
		{"Ivan", "1238763218", 1, 46, 2.9},
		{"Stipe", "9867264873", 2, 37, 1.2},
		{"Ana", "138640192", 3, 55, 4.5},
		{"Goran", "2148502832", 1, 0, 3.7} };

	size_t dulj = sizeof(studenti) / sizeof(student);

	cout << "studenti prve godine sa barem jednim polozenim predmetom: " << endl;
	filter(studenti, dulj, ispis, [](student& s) {return s.godina == 1 && s.ECTS >= 7; });
	cout << " " << endl;

	cout << "studenti sa prosjekom vecim od 3.5: " << endl;
	filter(studenti, dulj, ispis, [](student& s) {return s.prosjek > 3.5; });
	cout << " " << endl;
	
	
	filter(studenti, dulj, povecaj, [](student& s) { return s.ECTS >= 45; });
	
	cout << "studenti koji su presli na iducu godinu :" << endl;
	for (size_t i = 0; i < dulj; i++) {
		student& s = studenti[i];
		if (s.ECTS >= 45) {
			ispis(s);
		}
	}

	return 0;
}