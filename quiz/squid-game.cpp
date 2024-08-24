#include <cstdint>
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
    int k;
    cin >> k;
    while (k--) {
        int n, total = 0, min = INT32_MAX, tmp;
        cin >> n;
        while (n--) {
            cin >> tmp;
            total += tmp;
            if (tmp < min)
                min = tmp;
        }
        total -= min;
        cout << total << '\n';
    }
    return 0;
}