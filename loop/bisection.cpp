#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*
    x = log10(a)
    10 ^ x = a;
    pow(10, x) = a;
    */
    double lower = 0, upper, target, candidate = 0, mid;
    cin >> target;
    upper = target;
    while (true) {
        mid = (lower + upper) / 2;
        candidate = pow(10, mid);
        if (abs(target - candidate) <= 1e-10 * max(target, candidate)) break;
        if (candidate > target) upper = mid;
        else lower = mid;
    }
    cout << mid;
    return 0;
}
