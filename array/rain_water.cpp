#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> col;
    int n;
    cin >> n;
    col.resize(n);
    for (auto &c : col)
        cin >> c;

    int water = 0, lmax = 0, rmax = 0, l = 0, r = n - 1;
    while (l <= r) {
        if (rmax <= lmax) {
            water += max(0, rmax - col[r]);
            rmax = max(rmax, col[r]);
            r--;
        } else {
            water += max(0, lmax - col[l]);
            lmax = max(lmax, col[l]);
            l++;
        }
    }
    cout << water;
    return 0;
}
