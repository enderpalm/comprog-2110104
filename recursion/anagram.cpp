#include <iostream>
#include <set>

using namespace std;

set<string> anagrams;

void combine(int idx, string &buf, string &original) {
    if (idx == 0) {
        anagrams.insert(buf);
        return;
    }
    for (auto it = original.begin(); it != original.end(); it++) {
        auto c = *it;
        buf.push_back(c);
        original.erase(it);
        combine(idx - 1, buf, original);
        original.insert(it, c);
        buf.pop_back();
    }
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string original;
    cin >> original;
    string buf = "";
    combine(original.length(), buf, original);
    for (auto &a : anagrams)
        cout << a << ' ';
    return 0;
}
