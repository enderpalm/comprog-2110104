#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> winner;
set<string> loser;

int main(int argc, const char **argv) {
    string w, l;
    while (cin >> w >> l) {
        winner.insert(w);
        loser.insert(l);
    }
    bool none = true;
    for (auto &e : winner) {
        if (loser.find(e) == loser.end()) {
            cout << e << ' ';
            none = false;
        }
    }
    if (none) cout << "None";
    return 0;
}