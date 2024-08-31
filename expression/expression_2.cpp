#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x;
    cin >> x;
    double res = pow(x, sqrt(2 * log(x + 1))) / (10 - x);
    cout << round(res * 1e6) / 1e6;
    return 0;
}
