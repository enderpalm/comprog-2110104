#include <iostream>
#include <set>
#include <sstream>

using namespace std;

void print_set(set<int> &s, char label) {
    cout << label << ':';
    if (s.empty()) cout << " empty set";
    else
        for (auto &t : s)
            cout << ' ' << t;
    cout << '\n';
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    set<int> unio, diff, intsct;
    int tmp;
    bool first = true;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        set<int> buf;
        while (ss >> tmp) {
            unio.insert(tmp); // union

            // intersection
            if (first) intsct.insert(tmp);
            else if (intsct.find(tmp) != intsct.end()) buf.insert(tmp);

            // difference
            if (first) diff.insert(tmp);
            else diff.erase(tmp);
        }
        if (!first) intsct = buf;
        first = false;
    }
    print_set(unio, 'U');
    print_set(intsct, 'I');
    print_set(diff, 'D');
    return 0;
}
