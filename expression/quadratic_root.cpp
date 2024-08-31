#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a, b, c;
    cin >> a >> b >> c;
    double discr = sqrt(b * b - 4 * a * c) / (2 * a);
    double front = -b / (2 * a);
    cout << round((front - discr) * 1e3) / 1e3 << ' ';
    cout << round((front + discr) * 1e3) / 1e3;
    return 0;
}
