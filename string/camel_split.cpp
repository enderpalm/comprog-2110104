#include <cctype>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string msg;
    cin >> msg;
    bool first = true;
    bool found_dig = false;
    for (auto &m : msg) {
        if (isupper(m) && !first) {
            cout << ", ";
            found_dig = false;
        } else if (isdigit(m)) {
            if (!found_dig && !first) cout << ", ";
            found_dig = true;
        } else if (found_dig && !first) {
            cout << ", ";
            found_dig = false;
        }
        cout << m;
        first = false;
    }
    return 0;
}
