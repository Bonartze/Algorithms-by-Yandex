#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, string> synonyms;
    size_t n;
    string word;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        string word, synonym;
        cin >> word >> synonym;
        synonyms[word] = synonym;
        synonyms[synonym] = word;
    }
    cin >> word;
    cout << synonyms[word] << endl;
    return 0;
}