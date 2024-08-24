#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int wgh;
    cin >> wgh;
    if (wgh > 2000)
        cout << "Reject";
    else if (wgh > 1000)
        cout << 58;
    else if (wgh > 500)
        cout << 38;
    else if (wgh > 250)
        cout << 28;
    else if (wgh > 100)
        cout << 22;
    else
        cout << 18;
    return 0;
}
