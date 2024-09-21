#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char **argv) {
    long long n, amount = 0;
    cin >> n;
    string order;
    while (cin >> order)
        amount += stol(order.substr(1));
    cout << amount * n;
    return 0;
}