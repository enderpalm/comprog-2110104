#include <iostream>
#include <set>

using namespace std;

set<int> dup;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tmp;
    int found = -2, i = 0;
    while (cin >> tmp) {
        if (found != -2) continue;
        if (dup.find(tmp) != dup.end()) found = i;
        else dup.insert(tmp);
        i++;
    }
    cout << (found + 1);
    return 0;
}
