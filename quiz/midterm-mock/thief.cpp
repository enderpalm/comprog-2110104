#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
    int n, target;
    cin >> n >> target;
    int weights[n];
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                total += weights[k];
            }
            if (total == target) {
                cout << i << ' ' << weights[i] << '\n';
                cout << j << ' ' << weights[j];
                return 0;
            }
        }
    }
    return 0;
}