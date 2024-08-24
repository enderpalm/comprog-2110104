#include <iostream>
#include <math.h>

using namespace std;

int divisor[4] = {1, 1000, 1000000, 1000000000};
char deg2dig[3] = {'K', 'M', 'B'};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    cin >> raw;
    int deg = (raw.length() - 1) / 3;
    int places = (raw.length() - 1) % 3;

    if (deg < 4) {
        if (places == 0)
            cout << round(stod(raw) / divisor[deg] * 10) / 10.0;
        else
            cout << round(stod(raw) / divisor[deg]);

        if (deg > 0)
            cout << deg2dig[deg - 1];
    } else
        cout << round(stod(raw) / divisor[3]) << deg2dig[2];
    return 0;
}
