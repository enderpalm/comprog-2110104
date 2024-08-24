#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void flip(vector<int> &pancake, int last_idx) {
    reverse(pancake.begin(), pancake.begin() + last_idx + 1);
}

void print_pancake(vector<int> &pancake) {
    for (auto &p : pancake)
        cout << p << ' ';
    cout << '\n';
}

int main(int argc, const char **argv) {
    int n;
    cin >> n;
    vector<int> pancake;
    pancake.resize(n);
    for (int &p : pancake)
        cin >> p;
    print_pancake(pancake);
    for (int i = n - 1; i > 0; i--) {
        int max_idx =
            max_element(pancake.begin(), pancake.begin() + i + 1) - pancake.begin();
        if (max_idx != i) {
            if (max_idx != 0) {
                flip(pancake, max_idx);
                print_pancake(pancake);
            }
            flip(pancake, i);
            print_pancake(pancake);
        }
    }
    return 0;
}