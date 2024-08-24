#include <iostream>

using namespace std;

bool board[20][20];

bool valid(int row, int col, int n) {
    // check horizontal
    for (int i = 0; i < n; i++) {
        if (i == col)
            continue;
        if (board[row][i])
            return false;
    }

    // check vertical
    for (int i = 0; i < n; i++) {
        if (i == row)
            continue;
        if (board[i][col])
            return false;
    }

    // first diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;
    // board[i][j] = true;
    // second diagonal
    for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
        if (board[i][j])
            return false;
    // board[i][j] = true;
    // third diagonal
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    // board[i][j] = true;
    // fourth diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    // board[i][j] = true;

    return true;
}

int main(int argc, const char **argv) {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char in;
            cin >> in;
            board[i][j] = (in == 'Q');
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (!board[i][j]) cout << '-';
            else cout << (valid(i, j, n) ? 'Q' : '-');
        }
        cout << '\n';
    }
    return 0;
}