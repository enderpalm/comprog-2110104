#include <iostream>
#include <string>

using namespace std;

int board[5][5];
bool checked[5][5];
char idx2code[5] = {'B', 'I', 'N', 'G', 'O'};

int max_action = 0, win_row = -1, win_col = -1, action_count = 0;

/**
 * -1 = descending | 0 = not win | 1 = ascending
 */
int win_diag = 0;

string idx_n_val_to_code(int col, int val) {
    return idx2code[col] + to_string(val);
}

int head2idx(char c) {
    switch (c) {
    case 'B':
        return 0;
    case 'I':
        return 1;
    case 'N':
        return 2;
    case 'G':
        return 3;
    }
    return 4;
}

void check_win(int row, int col) {

    bool res = true;
    for (int i = 0; i < 5; i++) {
        if (!checked[row][i]) {
            res = false;
            break;
        }
    }
    if (res && win_row == -1) {
        max_action = action_count;
        win_row = row;
    }

    // --------------------------- //

    res = true;
    for (int i = 0; i < 5; i++) {
        if (!checked[i][col]) {
            res = false;
            break;
        }
    }
    if (res && win_col == -1) {
        max_action = action_count;
        win_col = col;
    }

    // --------------------------- //

    res = true;
    if (row == col) {
        for (int i = 0; i < 5; i++) {
            if (!checked[i][i]) {
                res = false;
                break;
            }
        }
        if (res && win_diag == 0) {
            max_action = action_count;
            win_diag = -1;
        }
    }

    res = true;
    if (row + col == 4) {
        for (int i = 0; i < 5; i++) {
            if (!checked[4 - i][i]) {
                res = false;
                break;
            }
        }
        if (res && win_diag == 0) {
            max_action = action_count;
            win_diag = 1;
        }
    }
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                char in;
                cin >> in;
                board[i][j] = 76;
                checked[i][j] = true;
                continue;
            }
            cin >> board[i][j];
        }
    }
    while (cin >> tmp) {
        action_count++;
        int col = head2idx(tmp[0]);
        int val = stoi(tmp.substr(1));
        for (int i = 0; i < 5; i++) {
            if (board[i][col] == val) {
                checked[i][col] = true;
                check_win(i, col);
                break;
            }
        }
    }
    cout << max_action << '\n';
    if (win_row != -1) {
        for (int i = 0; i < 5; i++) {
            if (win_row == 2 && i == 2)
                continue;
            if (i != 0)
                cout << ", ";
            cout << idx_n_val_to_code(i, board[win_row][i]);
        }
        cout << '\n';
    }
    if (win_col != -1) {
        for (int i = 0; i < 5; i++) {
            if (win_col == 2 && i == 2)
                continue;
            if (i != 0)
                cout << ", ";
            cout << idx_n_val_to_code(win_col, board[i][win_col]);
        }
        cout << '\n';
    }
    if (win_diag != 0) {
        for (int i = 0; i < 5; i++) {
            if (i == 2)
                continue;
            if (i != 0)
                cout << ", ";
            cout << idx_n_val_to_code(i, board[win_diag == 1 ? (4 - i) : i][i]);
        }
        cout << '\n';
    }
    return 0;
}
