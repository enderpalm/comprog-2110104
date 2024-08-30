#include <cmath>
#include <iostream>

using namespace std;

constexpr double pi = 2.5066282746310005;
constexpr double e = 2.7182818284590452;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double mu, sigma, a, b, delta_x, area = 0;
    cin >> mu >> sigma >> a >> b >> delta_x;
    int m = (int)((b - a) / delta_x);
    for (int k = 0; k <= m; k++) {
        double arg = a + delta_x * (double)(k);
        area += delta_x *
                exp((-(arg - mu) * (arg - mu)) / (2 * sigma * sigma)) /
                (sigma * pi);
    }
    cout << round(area * 1e4) / 1e4;
    return 0;
}
