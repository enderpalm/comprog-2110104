#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
    double x;
    cin >> x;
    double x2rad = x * 3.141592653 / 180;
    double xcos = cos(x2rad);
    cout << fixed << setprecision(1)
         << sqrt(x * x + xcos * xcos) /
                (sin(x2rad) + (xcos * xcos * xcos / (x * x + 1)));
    return 0;
}