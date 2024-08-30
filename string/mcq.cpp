#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string key, ans;
    getline(cin, key);
    getline(cin, ans);
    if (key.length() != ans.length()) {
        cout << "Incomplete answer";
        return 0;
    }
    int correct = 0;
    for (int i = 0; i < key.length(); i++)
        if (key[i] == ans[i]) correct++;
    cout << correct;
    return 0;
}
