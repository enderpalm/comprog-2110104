#include <iostream>
#include <string>

#define print_steak()                                                          \
    for (int i = 0; i < steak; i++)                                            \
    cout << prev

using namespace std;

int main(int argc, const char **argv) {
    string raw;
    int lim;
    cin >> raw >> lim;
    char prev = raw[0];
    int steak = 0;
    for (auto &c : raw) {
        if (c == prev)
            steak++;
        else {
            if (steak < lim) {
                print_steak();
            }
            prev = c;
            steak = 1;
        }
    }
    if (steak < lim)
        print_steak();
    return 0;
}