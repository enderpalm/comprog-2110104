#include <iostream>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n == 0) cout << "zero\neven";
    else {
        cout << (n > 0 ? "positive\n": "negative\n");
        cout << (n & 1 ? "odd" : "even");
    }
    return 0;
}
