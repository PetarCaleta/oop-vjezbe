#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>

using namespace std;

class TempLog {
private:
    vector<double> temps;
public:

    void addTemp(double t) {
        if (t < -50 || t > 50) {
            throw out_of_range("temp mora biti izmedu -50 i 50");
        }
        temps.push_back(t);
    }

    void removeTemp() {
        
        temps.erase(remove_if(temps.begin(), temps.end(), 
            [](double x) { return x < -10 || x > 40; }), temps.end());
    }
};


int main() {

   

    return 0;
}