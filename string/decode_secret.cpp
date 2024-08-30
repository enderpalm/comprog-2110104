#include <cctype>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    while (getline(cin, raw)) {
        bool actual = false;
        char sentinel = raw[raw.length() - 1];
        for (int i = 0; i < raw.length(); i++) {
            if (raw[i] == sentinel) {
                actual = !actual;
                continue;
            }
            if (actual) cout << raw[i];
        }
        cout << '\n';
    }
    return 0;
}
