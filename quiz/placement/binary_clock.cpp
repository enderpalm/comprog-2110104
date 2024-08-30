#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string time;
    cin >> time;
    int dig[6];
    int j = 0;
    for (int i = 0; i < 6; i++) {
        dig[i] = time[j] - '0';
        if (i == 1 || i == 3)
            j += 2;
        else
            j++;
    }
    for (int i = 3; i >= 0; i--) {
        for (j = 0; j < 6; j++) {
            if (i == 3 && !(j & 1) || (i == 2 && j == 0)) {
                cout << ' ';
                continue;
            }
            cout << ((dig[j] & (1 << i)) != 0);
        }
        cout << '\n';
    }
    return 0;
}
