#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void reverse_strings(vector<string>& words) {
    for (auto& word : words) {
        reverse(word.begin(), word.end());
    }
}

int main() {
    vector<string> words = { "hello", "world", "c++" };

    cout << "Prije: ";
    for (const auto& w : words)
        cout << w << " ";
    cout << endl;

    reverse_strings(words);

    cout << "Nakon: ";
    for (const auto& w : words)
        cout << w << " ";
    cout << endl;

    return 0;
}