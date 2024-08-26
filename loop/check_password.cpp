#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string pwd;
    while (getline(cin, pwd)) {
        bool found_upper = false, found_lower = false, found_num = false, found_special = false;
        for (auto &p : pwd) {
            if (isupper(p)) found_upper = true;
            else if (islower(p)) found_lower = true;
            else if (isdigit(p)) found_num = true;
            else found_special = true;
        }
        bool strong = pwd.length() >= 12 && found_upper && found_lower &&
                      found_num && found_special;
        bool weak =
            pwd.length() >= 8 && found_upper && found_lower && found_num;
        cout << ">> ";
        if (strong) cout << "strong\n";
        else if (weak) cout << "weak\n";
        else cout << "invalid\n";
    }
    return 0;
}
