#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

string to_lower(string str) {
    for (auto &i: str) i = tolower(i);
    return str;
}

bool is_number(string str) {
    for (auto &i: str)
        if (!isdigit(i))
            return false;
    return true;
}

string indefecator() {
    unordered_map<string, int> freq_ind;
    fstream f("input.txt");
    string c, d;
    vector<string> queue_words;
    int key_words;
    unordered_set<string> key_wrds;
    f >> key_words >> c >> d;
    for (int i = 0; i < key_words; i++) {
        string tmp;
        f >> tmp;
        if (c == "no")
            tmp = to_lower(tmp);
        key_wrds.insert(tmp);
    }
    char lit;
    string word = "";
    while (f >> noskipws >> lit) {
        if (isalpha(lit) || (isdigit(lit))) {
            if (c == "no")
                lit = tolower(lit);
            word += lit;
        } else if (!word.empty() && key_wrds.find(word) == key_wrds.end()) {
            if (freq_ind[word] == 0)
                queue_words.push_back(word);
            if ((d == "no" && !isdigit(word[0])) || (d == "yes") && !is_number(word))
                freq_ind[word]++;
            word.clear();
        } else if (!word.empty())
            word.clear();
    }
    if (!word.empty())
        freq_ind[word]++;
    string result = " ";
    int k = 0;
   for (auto &[i, j]: freq_ind) {
        if (j > k) {
            result = i;
            k = j;
        } else if (j == k && (find(queue_words.begin(), queue_words.end(), result) - queue_words.begin() >
                              find(queue_words.begin(), queue_words.end(), i) - queue_words.begin())) {
            result = i;
            k = j;
        }
    }
    return result;
}

int main() {
    cout << indefecator();
    return 0;
}