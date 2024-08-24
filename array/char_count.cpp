#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int freq[26];

int main(int argc, const char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    getline(cin, line);
    for (auto &c : line) {
        if (!isalpha(c))
            continue;
        freq[tolower(c) - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i])
            cout << static_cast<char>(i + 'a') << " -> " << freq[i] << '\n';
    }
    return 0;
}