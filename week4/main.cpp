#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    unordered_map<string, int> number_entrance;
    fstream f("input.txt");
    string str;
    while (f >> str) {
        if (number_entrance.find(str) == number_entrance.end()) {
            number_entrance[str] = 0;
            cout << number_entrance[str]++<<' ';
        } else
            cout << number_entrance[str]++<<' ';
    }
}
