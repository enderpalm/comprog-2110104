#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> seq;
    int n;
    cin >> n;
    seq.push_back(n);
    while (n != 1) {
        if (n & 1)
            n = 3 * n + 1;
        else
            n >>= 1;
        seq.push_back(n);
    }
    int i = seq.size() > 15 ? seq.size() - 15 : 0;
    for (; i < seq.size(); i++) {
        cout << seq[i];
        if (i != seq.size() - 1)
            cout << "->";
    }
    return 0;
}
