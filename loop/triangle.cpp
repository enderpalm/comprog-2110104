#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + n; j++) {
            cout << (j == i + n - 1 || j == n - i - 1 || i == n - 1 ? '*'
                                                                    : '.');
        }
        cout << '\n';
    }
    return 0;
}
