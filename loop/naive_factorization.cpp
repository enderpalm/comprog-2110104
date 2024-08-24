#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    bool first = true;
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            bool is_prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (!is_prime)
                continue;
            while (n % i == 0) {
                if (first)
                    first = false;
                else
                    cout << '*';
                cout << i;
                n /= i;
            }
        }
    }
    return 0;
}
