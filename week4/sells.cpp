#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main() {
    map<string, map<string, size_t>> notes;
    string name, product;
    size_t number;
    fstream f("input.txt");
    while (f >> name >> product >> number)
        notes[name][product] += number;
    for (auto &[i, j]: notes) {
        cout << i << ":" << endl;
        for (auto &[k, l]: j)
            cout << k << ' ' << l << endl;
    }
    return 0;
}
