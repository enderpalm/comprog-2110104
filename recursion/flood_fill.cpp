#include <iostream>

using namespace std;

const int R = 7, C = 7;

void floodfill(int x[][C], int r, int c, int e) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (x[r][c] != 0) return;
    x[r][c] = e;
    floodfill(x, r + 1, c ,e);
    floodfill(x, r - 1, c ,e);
    floodfill(x, r, c + 1 ,e);
    floodfill(x, r, c - 1 ,e);
}

int main(int argc, const char **argv) {
    int x[][C] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            cin >> x[r][c];
    int row, col, e;
    cin >> row >> col >> e;
    floodfill(x, row, col, e);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c)
            cout << x[r][c] << ' ';
        cout << endl;
    }
    return 0;
}