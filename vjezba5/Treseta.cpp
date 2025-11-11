#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>
using namespace std;

class Karta {
public:
    int broj;        
    string zog;      

    Karta(int b, string z) : broj(b), zog(z) {}

    void ispisi() const {
        cout << broj << " " << zog;
    }
};

class Mac {
private:
    vector<Karta> karte;
public:
    Mac() {
        vector<string> zogovi = { "kupe", "dinari", "bastoni", "spade" };
        for (auto& z : zogovi) {
            for (int b = 1; b <= 10; b++) {
                karte.emplace_back(b, z);
            }
        }
    }

    void promijesaj() {
        shuffle(karte.begin(), karte.end(), default_random_engine(time(nullptr)));
    }

    vector<Karta> podijeliIgracu() {
        vector<Karta> ruka(karte.begin(), karte.begin() + 10);
        karte.erase(karte.begin(), karte.begin() + 10);
        return ruka;
    }
};

class Igrac {
public:
    string ime;
    vector<Karta> ruka;
    int bodovi;

    Igrac(string i) : ime(i), bodovi(0) {}

    void postaviRuku(vector<Karta> k) {
        ruka = k;
    }

    void ispisiRuku() const {
        cout << "Ruka igraca " << ime << ":\n";
        for (auto& k : ruka) {
            k.ispisi();
            cout << ", ";
        }
        cout << "\n";
    }

    void izracunajAkuzu() {
        
        map<string, vector<int>> poZogu;
        for (auto& k : ruka)
            poZogu[k.zog].push_back(k.broj);

        for (auto& par : poZogu) {
            vector<int> brojevi = par.second;
            bool ima1 = find(brojevi.begin(), brojevi.end(), 1) != brojevi.end();
            bool ima2 = find(brojevi.begin(), brojevi.end(), 2) != brojevi.end();
            bool ima3 = find(brojevi.begin(), brojevi.end(), 3) != brojevi.end();
            if (ima1 && ima2 && ima3) {
                bodovi += 3;
            }
        }

        map<int, int> brojac;
        for (auto& k : ruka) {
            if (k.broj >= 1 && k.broj <= 3)
                brojac[k.broj]++;
        }

        for (auto& par : brojac) {
            if (par.second == 3)
                bodovi += 3;
            else if (par.second == 4)
                bodovi += 4;
        }
    }
};

int main() {
    int brojIgraca;
    cout << "Unesite broj igraca (2 ili 4): ";
    cin >> brojIgraca;

    if (brojIgraca != 2 && brojIgraca != 4) {
        cout << "Broj igraca mora biti 2 ili 4!\n";
        return 0;
    }

    vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; i++) {
        string ime;
        cout << "Unesite ime igraca " << i + 1 << ": ";
        cin >> ime;
        igraci.emplace_back(ime);
    }

    Mac mac;
    mac.promijesaj();

    for (auto& igrac : igraci) {
        igrac.postaviRuku(mac.podijeliIgracu());
        igrac.izracunajAkuzu();
        igrac.ispisiRuku();
        cout << "Akuža bodovi: " << igrac.bodovi << "\n\n";
    }

    cout << "=== Rezultati akuže ===\n";
    for (auto& igrac : igraci) {
        cout << igrac.ime << ": " << igrac.bodovi << " bodova\n";
    }

    return 0;
}