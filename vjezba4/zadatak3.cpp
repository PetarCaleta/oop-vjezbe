#include <iostream>
#include <string>
using namespace std;

void fix_spaces(string& text) {
    for (size_t i = 0; i + 1 < text.size(); ) {
        if (text[i] == ' ' && text[i + 1] == ' ') {
            text.erase(i, 1);
        }
        else {
            ++i;
        }
    }
    for (size_t i = 0; i < text.size(); ) {
        if ((text[i] == ',' || text[i] == '.') && i > 0 && text[i - 1] == ' ') {
            text.erase(i - 1, 1);
            if (i > 0) --i;
        }
        else {
            ++i;
        }
    }

    for (size_t i = 0; i + 1 < text.size(); ++i) {
        if (text[i] == ',' && text[i + 1] != ' ') {
            text.insert(i + 1, " ");
        }
    }
}

int main() {
    string s = "Puno   razmaka ,i  tocka .";

    fix_spaces(s);

    cout << s << endl;

    return 0;
}