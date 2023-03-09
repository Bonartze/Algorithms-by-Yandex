#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<size_t, size_t> h_w;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        size_t tempi, tempj;
        cin >> tempi >> tempj;
        if (tempj > h_w[tempi])
            h_w[tempi] = tempj;
    }
    size_t sum = 0;
    for (auto &[i, j]: h_w)
        sum += j;
    cout << sum << endl;
    return 0;
}
