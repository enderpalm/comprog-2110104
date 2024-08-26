#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define osc_inst                                                               \
    if (back) arr.push_back(tmp);                                              \
    else arr.insert(arr.begin(), tmp);                                         \
    back = !back;

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool back = true;
    vector<int> arr;
    int n, tmp;
    cin >> n;
    arr.reserve(n);
    while (n--) {
        cin >> tmp;
        osc_inst
    }
    cin.ignore();
    string raw;
    getline(cin, raw);
    stringstream ss(raw);
    while (ss >> tmp) {
        osc_inst
    }
    while (cin >> tmp) {
        if (tmp == -1) break;
        osc_inst
    }
    cout << '[';
    bool first = true;
    for (auto &a : arr) {
        if (first) first = false;
        else cout << ", ";
        cout << a;
    }
    cout << ']';
    return 0;
}
