#include <iostream>
#include <string>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    getline(cin, raw);
    for (auto &r : raw) {
        if (r == '(') cout << '[';
        else if (r == '[') cout << '(';
        else if (r == ')') cout << ']';
        else if (r == ']') cout << ')';
        else cout << r;
    }
    return 0;
}
