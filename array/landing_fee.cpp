#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> coun2fees;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string country, prev;
    int n, fee, total = 0;
    cin >> n;
    coun2fees.reserve(n);
    while (n--) {
        cin >> country >> fee;
        coun2fees[country] = fee;
    }
    cin >> country;
    prev = country.substr(4, 2);
    while (cin >> country) {
        string cur = country.substr(4, 2);
        if (cur != prev)
            total += coun2fees[cur];
        prev = cur;
    }
    cout << total;
    return 0;
}
