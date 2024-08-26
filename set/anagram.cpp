#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string raw;
    multiset<char> table[2];
    for (int i = 0; i < 2; i++) {
        getline(cin, raw);
        for (auto &r : raw) {
            if (r == ' ') continue;
            table[i].insert(tolower(r));
        }
    }
    cout << (table[0] == table[1] ? "YES" : "NO");
    return 0;
}
