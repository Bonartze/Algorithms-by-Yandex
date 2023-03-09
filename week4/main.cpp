#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


int main() {
    int n, k;
    unordered_map<size_t, int> num_keys;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> num_keys[i + 1];
    cin >> k;
    vector<size_t> seq_prk(k);
    for (int i = 0; i < k; i++) {
        cin >> seq_prk[i];
        num_keys[seq_prk[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        if (num_keys[i] < 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
