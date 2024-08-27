#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> table;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, n, m;
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        table[a] = b;
    }
    for (int i = 1; i <= n; i++) {
        int mode = 0;
        int mode_freq = -1;
        unordered_map<int, int> num2freq;
        for (int j = max(1, i - k); j <= min(n, i + k); j++) {
            if (table.find(j) != table.end())
                num2freq[table[j]]++;
        }
        if (num2freq.empty()) {
            cout << "X ";
            continue;
        }
        for (auto &f : num2freq) {
            if (f.second > mode_freq ||
                (f.second == mode_freq && f.first < mode)) {
                mode_freq = f.second;
                mode = f.first;
            }
        }
        cout << mode << ' ';
    }
    return 0;
}
