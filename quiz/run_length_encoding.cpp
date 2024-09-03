#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    cin >> raw;
    char prev = raw[0];
    int steak = 1;
    for (int i = 1; i < raw.length(); i++) {
        if (prev == raw[i]) steak++;
        else {
            cout << prev << ' ' << steak << ' ';
            steak = 1;
        }
        prev = raw[i];
    }
    if (steak) cout << prev << ' ' << steak;
    return 0;
}
