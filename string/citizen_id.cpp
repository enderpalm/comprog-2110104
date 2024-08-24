#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char** argv) {
    string raw;
    cin >> raw;
    int sum = 0;
    for (int i = 0; i < 12; i++) {
        sum += (13 - i) * static_cast<int>(raw[i] - '0');
        cout << raw[i];
        if (i == 0 || i == 4 || i == 9 || i == 11) cout << '-';
    }
    cout << (11 - sum % 11) % 10;
    return 0;
}