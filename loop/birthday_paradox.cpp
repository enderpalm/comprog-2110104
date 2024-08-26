#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    float p, k = 1, t = 1;
    cin >> p;
    while (true) {
        t = t * (365 - (k - 1)) / 365;
        if (1 - t >= p) break;
        k++;
    }
    cout << k;
    return 0;
}
