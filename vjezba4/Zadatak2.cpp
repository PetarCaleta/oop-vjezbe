#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void input_vector(vector<int>& v) {
	int x;
	while (1) {
		cout << "unesi broj: ";
		cin >> x;
		if (x == 0) {
			return;
		}
		v.push_back(x);
	}
}

void print_vector(const vector<int>& v) {
	for (int x : v) {
		cout << x << " ";
	}
	cout << " " << endl;
}

vector<int> jedinstveni(vector<int> v) {
	vector<int> jedini;
	for ( int x : v){
		auto it = find(jedini.begin(), jedini.end(), x);
		if (it == jedini.end()) {
			jedini.push_back(x);
		}

	}
	return jedini;
}



int main() {

	vector<int> cijeli;

	cout << "unesi cijele brojeve (0 za kraj):" << endl;
	input_vector(cijeli);
	vector<int> rezultat = jedinstveni(cijeli);
	print_vector(rezultat);

	sort(rezultat.begin(), rezultat.end(), [](int a, int b)
	{return  abs(a) < abs(b); });
	
	cout << "sortirani po apsolutnoj:" << endl;
	print_vector(rezultat);


	return 0;
}