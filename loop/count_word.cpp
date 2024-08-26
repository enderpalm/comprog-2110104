#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// naive string matching
int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int count = 0;
    string pat, line;
    cin >> pat;
    cin.ignore();
    getline(cin, line);
    for (int i = 0; i <= line.length() - pat.length() + 1; i++) {
        bool valid = true;
        if (i != 0 && isalpha(line[i - 1])) valid = false;
        for (int j = 0; j < pat.length() && valid; j++)
            if (line[i + j] != pat[j]) valid = false;
        if (isalpha(line[i + pat.length()])) valid = false;

        if (valid) count++;
    }
    cout << count;
    return 0;
}
