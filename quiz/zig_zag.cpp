#include <climits>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char **argv) {
    int n, a_min = INT_MAX, a_max = INT_MIN, b_min = INT_MAX, b_max = INT_MIN,
           tmp_1, tmp_2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp_1 >> tmp_2;
        // (i & 1) -> tmp_1 = b, tmp_2 = a
        a_min = min(a_min, i & 1 ? tmp_2 : tmp_1);
        a_max = max(a_max, i & 1 ? tmp_2 : tmp_1);
        b_min = min(b_min, i & 1 ? tmp_1 : tmp_2);
        b_max = max(b_max, i & 1 ? tmp_1 : tmp_2);
    }
    string opcode;
    cin >> opcode;
    if (opcode == "Zig-Zag") cout << a_min << ' ' << b_max;
    else cout << b_min << ' ' << a_max;
    return 0;
}