#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string To_lower(string str) {
    for (auto &i: str) i = tolower(i);
    return str;
}

size_t mistakes(string &text, unordered_map<string, unordered_set<string>> dictionary) {
    size_t mistakes = 0;
    stringstream t(text);
    string w;
    while (t >> w) {
        if ((dictionary.find(To_lower(w)) != dictionary.end() &&
             dictionary[To_lower(w)].find(w) == dictionary[To_lower(w)].end()) ||
            (dictionary.find(To_lower(w)) == dictionary.end() && count_if(w.begin(), w.end(), [](char c) {
                return isupper(c);
            }) != 1))
            mistakes++;
    }
    return mistakes;
}

int main() {
    size_t n;
    cin >> n;
    unordered_map<string, unordered_set<string>> dict;
    for (size_t i = 0; i < n; i++) {
        string word;
        cin >> word;
        dict[To_lower(word)].insert(word);
    }
    cin.ignore();
    string text;
    getline(cin, text);
    cout << mistakes(text, dict) << endl;
    return 0;
}