#include <iostream>
#include <string>
using namespace std;

string word_to_pig_latin(const string& word) {
    if (word.empty()) return "";

    
    string vowels = "aeiouAEIOU";

    if (vowels.find(word[0]) != string::npos) {
        return word + "hay";
    }
    else {
        return word.substr(1) + word[0] + "ay";
    }
}

int main() {


    cout << word_to_pig_latin("apple") << endl; 
    cout << word_to_pig_latin("hello") << endl; 
    cout << word_to_pig_latin("string") << endl; 

    return 0;
}