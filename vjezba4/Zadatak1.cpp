#include <vector>
#include <iostream>

using namespace std;



void input_vector(vector<int>& v) {

	int x;
	while (1) {
		cout << "unesi broj: " << endl;
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


}


int main() {

	int x;
	vector <int> niz;
	input_vector(niz);
	print_vector(niz);


	return 0;
}