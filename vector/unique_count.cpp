#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    set<int> dup;
    string in;
    getline(cin, in);
    stringstream ss(in);
    while (ss >> n) dup.insert(n);
    n = 0;
    cout << dup.size() << '\n';
    for (auto &num : dup) {
        if (n >= 10) break;
        cout << num << ' ';
        n++;
    }
    return 0;
}
