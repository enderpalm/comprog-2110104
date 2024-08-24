#include <iostream>
#include <math.h>

using namespace std;

constexpr double pi = 3.141592653;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a = pi - (10.0 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2) / pow(8, 8);
    double b = pow(log(9.7), 7 / sqrt(71) - sin(40 * pi / 180));
    double c = pow(1.2, cbrt(2.3));
    cout << (a + b) / c;
    return 0;
}
