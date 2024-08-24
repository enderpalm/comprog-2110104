#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct rect {
    int ax;
    int ay;
    int bx;
    int by;
};

bool is_overlap(rect &first, rect &second) {
    return first.bx >= second.ax && first.ax <= second.bx &&
           first.by >= second.ay && first.ay <= second.by;
}

int calc_area(rect &first, rect &second) {
    int length = min(first.bx, second.bx) - max(first.ax, second.ax);
    int height = min(first.by, second.by) - max(first.ay, second.ay);
    return length * height;
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, ax, ay, bx, by;
    cin >> n;
    vector<rect> grid;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ax >> ay >> bx >> by;
        grid[i] = {ax, ay, bx, by};
    }
    bool no_overlaps = true;
    int max_area = INT_MIN;
    vector<pair<int, int>> rect_pair;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!is_overlap(grid[i], grid[j]))
                continue;
            int area = calc_area(grid[i], grid[j]);
            if (area == max_area)
                rect_pair.emplace_back(i, j);
            else if (area > max_area) {
                max_area = area;
                rect_pair.clear();
                rect_pair.emplace_back(i, j);
            }
            no_overlaps = false;
        }
    }
    if (no_overlaps || max_area == 0)
        cout << "No overlaps";
    else {
        cout << "Max overlapping area = " << max_area << '\n';
        for (auto &p : rect_pair)
            cout << "rectangles " << p.first << " and " << p.second << '\n';
    }
    return 0;
}
