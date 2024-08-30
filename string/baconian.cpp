#include <cctype>
#include <iostream>
#include <string>

#define clamped_increment                                                      \
    key_ptr++;                                                                 \
    if (key_ptr >= key.length()) key_ptr = 0;

#define skip_non_alpha                                                         \
    while (!isalpha(key[key_ptr])) {                                           \
        cout << key[key_ptr];                                                  \
        clamped_increment                                                      \
    }

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string key = "", recieved = "";
    char opcode = 'D';
    getline(cin, key);
    while (cin >> opcode) {
        if (opcode == 'D') {
            cin.ignore();
            getline(cin, recieved);
            int i = 3, code = 0;
            for (auto &r : recieved) {
                if (!isalpha(r)) continue;
                if (i != 0) code = code | ((islower(r) != 0) << i);
                if (i > 0) {
                    i--;
                    continue;
                }
                if (islower(r)) code++;
                i = 3;
                if (code == 10) cout << '-';
                else if (code == 11) cout << ',';
                else cout << code;
                code = 0;
            }
        } else {
            cin.ignore();
            getline(cin, recieved);
            int key_ptr = 0;
            skip_non_alpha for (auto &r : recieved) {
                int code = 0;
                if (r == '-') code = 10;
                else if (r == ',') code = 11;
                else code = r - '0';
                for (int shift = 3; shift >= 0; shift--) {
                    skip_non_alpha;
                    if (code & (1 << shift))
                        cout << (char)tolower(key[key_ptr]);
                    else cout << (char)toupper(key[key_ptr]);
                    clamped_increment
                }
            }
        }
        cout << '\n';
    }
    return 0;
}
