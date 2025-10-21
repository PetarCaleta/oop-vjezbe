#include <iostream>
using namespace std;

void unos(double** mat, int m, int n) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "unesi element ["<< i <<"][" << j << "]";
			cin >> mat[i][j];
		}
	}
}

void generiraj(double** mat, int m, int n, int a, int b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "unesi elemente [" << i << "][" << j << "]u rasponu[" << a << "," << b << "]";
			cin >> mat[i][j];
		}
	}

}
void ispis(double** mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}


double** zbroji(double** matA, double** matB, int m, int n) {
	double** matC = new double*[m];
	for (int i = 0; i < m; i++) {
		matC[i] = new double[n];
		for (int j = 0; j < n; j++) {
			matC[i][j] = matA[i][j] + matB[i][j];
		}
	}
	return matC;

}

double** oduzmi(double** matA, double** matB, int m, int n) {
	double** matC = new double* [m];
	for (int i = 0; i < m; i++) {
		matC[i] = new double[n];
		for (int j = 0; j < n; j++) {
			matC[i][j] = matA[i][j] - matB[i][j];

		}
	}
	return matC;
}
double** mnozi(double** matA, double** matB, int m, int n) {
	double** matC = new double* [m];
	for (int i = 0; i < m; i++) {
		matC[i] = new double[n];
		for (int j = 0; j < n; j++) {
			matC[i][j] = 0;
			for (int k = 0; k < n; k++) {
				matC[i][j] += matA[i][k] * matB[k][j];
			}

		}
	}
	return matC;
}

double** transponiranje(double** matA, int m, int n) {
	double** matT = new double* [n];
	for (int i = 0; i < n; i++) {
		matT[i] = new double[m];
		for (int j = 0; j < m; j++) {
			matT[i][j] = matA[j][i];
		}

	}
	return matT;
}


int main() {

	int m, n;


	cout << "broj redaka matrica:";
	cin >> m;
	cout << "broj stupaca matrica:";
	cin >> n;

	double** matA = new double* [m];
	double** matB = new double* [m];
	for (int i = 0; i < m; i++) {
		matA[i] = new double[n];
		matB[i] = new double[n];
	}
	cout << "unesi matricu A: \n";
	unos(matA, m, n);
	cout << "uensi matricu B: \n";
	unos(matB, m, n);

	cout << "matrica A:\n"; ispis(matA, m, n);
	cout << "matrica B:\n"; ispis(matB, m, n);


	double ** matC = zbroji(matA, matB, m, n);
	cout << "matA + matB\n"; ispis(matC, m, n);
	for (int i = 0; i < m; i++) {
		delete[] matC[i];
	}
	delete[] matC;

	double** matD = oduzmi(matA, matB, m, n);
	cout << "matA - matB\n"; ispis(matD, m, n);
	for (int i = 0; i < m; i++) {
		delete[] matD[i];
	}
	delete[] matD;

	
	double** matE = mnozi(matA, matB, m, n);
	cout << "matA * matB\n"; ispis(matE, m, n);
	for (int i = 0; i < m; i++) {
		delete[] matE[i];
	}
	delete[] matE;

	double** matT = transponiranje(matA, m, n);
	cout << "matA * matB\n"; ispis(matT, m, n);
	for (int i = 0; i < m; i++) {
		delete[] matT[i];
	}
	delete[] matT;


	for (int i = 0; i < m; i++) {
		delete[] matA[i];
	}
	delete[] matA;
	for (int i = 0; i < m; i++) {
		delete[] matB[i];
	}
	delete[] matB;


	return 0;
}
