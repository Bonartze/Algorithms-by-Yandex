#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    fstream f("input.txt");
    string operation;
    unordered_map<string, long> user;
    while (f >> operation) {
        if (operation == "DEPOSIT") {
            long sum;
            string name;
            f >> name >> sum;
            user[name] += sum;
        } else if (operation == "INCOME") {
            double per;
            f >> per;
            for (auto &[i, j]: user) {
                if (j >= 0)
                    user[i] += j * per / 100;
            }
        } else if (operation == "BALANCE") {
            string name;
            f >> name;
            if (user.find(name) == user.end())
                cout << "ERROR" << endl;
            else
                cout << user[name] << endl;
        } else if (operation == "TRANSFER") {
            string from, to;
            long sum;
            f >> from >> to >> sum;
            user[from] -= sum;
            user[to] += sum;
        } else if (operation == "WITHDRAW") {
            string name;
            long sum;
            f >> name >> sum;
            user[name] -= sum;
        }
    }
    return 0;
}
