#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int year;
    cin >> year;
    year = (year - 543) % 100;
    cout << (year + (year / 4) + 11) % 7;
    return 0;
}
