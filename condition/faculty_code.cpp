#include <cctype>
#include <iostream>

using namespace std;

int main(int  /*argc*/, const char**  /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string code;
    getline(cin, code);
    if (code.length() != 2) cout << "Error";
    else if (!isdigit(code[0]) || !isdigit(code[1])) cout << "Error";
    else if (code[0] == '0' && (code[1] == '1' || code[1] == '2')) cout << "OK";
    else if (code[0] == '2' || code[0] == '3') cout << "OK";
    else if (code == "40" || code == "51" || code == "53" || code == "55" || code == "58") cout << "OK";
    else cout << "Error";
    return 0;
}
