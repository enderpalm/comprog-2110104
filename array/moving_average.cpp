#include <cmath>
#include <iostream>

using namespace std;

float board[30][30];

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> board[i][j];

    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < c - 1; j++) {
            float sum = 0.0F;
            for (int k = -1; k <= 1; k++)
                for (int l = -1; l <= 1; l++)
                    sum += board[i + k][j + l];
            cout << round((sum / 9) * 100) / 100.0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
