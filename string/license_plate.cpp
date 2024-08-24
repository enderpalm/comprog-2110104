#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char **argv) {
    string original;
    int shift;
    cin >> original >> shift;

    int back = stoi(original.substr(4, 3));
    int carry = (back + shift) / 1000;
    back = (back + shift) % 1000;

    for (int i = 2; i > 0; i--) {
        carry += original[i] - 'A';
        original[i] = carry % 26 + 'A';
        carry /= 26;
    }

    carry += original[0] - '0';
    original[0] = (carry % 10) + '0';
    for (int i = 0; i < 3; i++)
        cout << original[i];
    cout << '-';
    for (int i = 3; i > to_string(back).length(); i--)
        cout << '0';
    cout << back;
    return 0;
}