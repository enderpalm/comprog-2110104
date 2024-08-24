#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    cin >> raw;
    raw += '$';
    vector<string> buf;
    buf.resize(raw.length());
    for (int i = 0; i < raw.length(); i++) {
        buf[i] = raw.substr(i, raw.length() - i) + raw.substr(0, i);
    }
    sort(buf.begin(), buf.end());
    for (auto &c : buf) {
        cout << c[raw.length() - 1];
    }
    return 0;
}
