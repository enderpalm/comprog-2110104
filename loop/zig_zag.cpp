#include <climits>
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, aMin = INT_MAX, aMax = INT_MIN, bMin = INT_MAX, bMax = INT_MIN;
    bool flag = true;
    while (cin >> a) {
        if (a == -998) {
            cout << aMin << ' ' << bMax;
            break;
        }
        if (a == -999) {
            cout << bMin << ' ' << aMax;
            break;
        }
        cin >> b;
        aMin = min(aMin, flag ? a : b);
        aMax = max(aMax, flag ? a : b);
        bMin = min(bMin, flag ? b : a);
        bMax = max(bMax, flag ? b : a);
        flag = !flag;
    }
    return 0;
}