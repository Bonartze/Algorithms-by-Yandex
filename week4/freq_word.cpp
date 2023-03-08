#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    unordered_map<string, int> most_fr;
    fstream f("input.txt");
    string str;
    string result;
    f >> result;
    int most = 0;
    while (f >> str) {
        most_fr[str]++;
        if (most_fr[str] > most || (strcmp(str.c_str(), result.c_str()) < 0) && most_fr[str] == most) {
            result = str;
            most = most_fr[str];
        }
    }
    cout << result;
    return 0;
}
