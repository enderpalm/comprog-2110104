#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int peak_cnt = 0, n, cur, prev, next;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
    cin >> prev >> cur;
    for (int i = 2; i < n; i++) {
        cin >> next;
        if (cur > prev && cur > next) peak_cnt++;
        prev = cur;
        cur = next;
    }
    cout << peak_cnt;
    return 0;
}
