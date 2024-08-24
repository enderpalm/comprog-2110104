#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double in, total = 0, min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < 4; i++) {
        cin >> in;
        total += in;
        if (in < min) min = in;
        if (in > max) max = in;
    }
    total = (total - (min + max)) / 2;
    cout << (round(total * 100.0) / 100.0);
    return 0;
}
