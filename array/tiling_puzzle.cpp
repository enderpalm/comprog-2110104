#include <iostream>
#include <vector>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, zero_row, inversions = 0;
    cin >> n;
    vector<int> board;
    board.resize(n * n);
    for (int i = 0; i < board.size(); i++) {
        cin >> board[i];
        if (board[i] == 0)
            zero_row = i / n;
    }
    for (int i = 0; i < board.size(); i++)
        for (int j = i + 1; j < board.size(); j++) {
            if (board[j] == 0)
                continue;
            if (board[i] > board[j])
                inversions++;
        }
    if ((n & 1 && !(inversions & 1)) ||
        ((!(n & 1) && ((inversions & 1) ^ (zero_row & 1)))))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
