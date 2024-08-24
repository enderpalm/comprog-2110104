#include <iostream>
#include <string>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string num;
    cin >> num;
    bool fail = false;
    if (num.length() != 10) fail = true;
    if (num[0] != '0' || (num[1] != '6' && num[1] != '8' && num[1] != '9')) fail = true;
    cout << (fail ? "Not a mobile" : "Mobile") << " number";
    return 0;
}
