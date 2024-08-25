#include <iostream>
#include <vector>

using namespace std;

int first_vowel(string &s) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u')
            return i;
    return -1;
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> pharses;
    string tmp;
    while (cin >> tmp)
        pharses.push_back(tmp);
    int last = pharses.size() - 1;
    int front_vowel = first_vowel(pharses[0]);
    int back_vowel = first_vowel(pharses[last]);
    cout << pharses[0].substr(0, front_vowel) +
                pharses[last].substr(back_vowel);
    for (int i = 1; i < last; i++)
        cout << ' ' << pharses[i];
    cout << ' '
         << pharses[last].substr(0, back_vowel) +
                pharses[0].substr(front_vowel);
    return 0;
}
