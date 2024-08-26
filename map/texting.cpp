#include <cctype>
#include <iostream>
#include <string>

using namespace std;

#define decode                                                                 \
    if (prev == '0') cout << ' ';                                              \
    else if (prev <= '6') cout << (char)('a' + 3 * (prev - '2') + steak - 1);  \
    else if (prev == '7') cout << (char)('p' + steak - 1);                     \
    else if (prev == '9') cout << (char)('w' + steak - 1);                     \
    else if (prev == '8') cout << (char)('t' + steak - 1);

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string recieved;
    while (getline(cin, recieved)) {
        cout << ">> ";
        if (recieved[0] == 'T') {
            for (int i = 4; i < recieved.length(); i++) {
                if (recieved[i] == ' ') {
                    cout << "0 ";
                    continue;
                }
                if (!isalpha(recieved[i])) continue;
                char lower = tolower(recieved[i]);
                if ('a' <= lower && lower <= 'o') {
                    int base = (lower - 'a') / 3 + 2;
                    int rep = (lower - 'a') % 3 + 1;
                    while (rep--)
                        cout << base;
                } else if ('t' <= lower && lower <= 'v') {
                    int rep = lower - 's';
                    while (rep--)
                        cout << 8;
                } else if (lower <= 's') {
                    int rep = lower - 'o';
                    while (rep--)
                        cout << 7;
                } else {
                    int rep = lower - 'v';
                    while (rep--)
                        cout << 9;
                }
                cout << ' ';
            }
            cout << '\n';
            continue;
        }
        int steak = 0;
        char prev = recieved[4];
        for (int i = 4; i < recieved.length(); i++) {
            if (!isdigit(recieved[i])) {
                decode steak = 0;
                continue;
            }
            steak++;
            prev = recieved[i];
        }
        decode cout << '\n';
    }
    return 0;
}