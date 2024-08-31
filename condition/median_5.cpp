#include <iostream>
#include <utility>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if (a > c) {
        swap(b, d);
        c = a;
    }
    a = e;
    if (a > b) swap(a, b);
    if (c > a) {
        swap(b, d);
        a = c;
    }
    cout << min(a, d);
    return 0;
}
