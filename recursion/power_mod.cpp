#include <iostream>
using namespace std;

int power_mod(int a, int k, int m) {
    if (k == 0) return 1;
    int lower = power_mod(a, k >> 1, m) % m;
    lower = (lower * lower) % m;
    if (k & 1) return ((a % m) * lower) % m;
    return lower;
}

int main(int argc, const char** argv) {
    int a, k, m;
    cin >> a >> k >> m;
    cout << power_mod(a, k ,m);
    return 0;
}