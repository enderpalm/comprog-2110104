#include <cctype>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool found[10] = {0};
    char tmp;
    while (cin >> tmp)
        if (isdigit(tmp)) found[tmp - '0'] = true;
    bool none = true, first = true;
    for (int i = 0; i < 10; i++) {
        if (!found[i]) {
            if (!first) cout << ',';
            cout << i;
            none = false;
            first = false;
        }
    }
    if (none) cout << "None";
    return 0;
}
