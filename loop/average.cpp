#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double sum = 0.0, tmp;
    int cnt = 0;
    while (true) {
        cin >> tmp;
        if (tmp == -1) {
            if (cnt == 0) cout << "No Data";
            else cout << round(sum / cnt * 100) / 100.0;
            return 0;
        }
        sum += tmp;
        cnt++;
    }
    return 0;
}
