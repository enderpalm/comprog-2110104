#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct interval {
    int data;
    int start;
    int end;
};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string buf;
    getline(cin, buf);
    stringstream ss(buf);

    vector<interval> ans;
    int n, prev, width = 1, max_width = -1, start = 0, end = 0;
    ss >> prev;
    while (ss >> n) {
        if (n == prev)
            width++;
        else {
            end = start + width - 1;
            if (width >= max_width) {
                if (width > max_width)
                    max_width = width;
                ans.push_back({prev, start, end});
            }
            width = 1;
            start = end + 1;
        }
        prev = n;
    }
    end = start + width - 1;
    if (width >= max_width)
        ans.push_back({prev, start, end});
    sort(ans.begin(), ans.end(), [](interval &lhs, interval &rhs) {
        return lhs.data == rhs.data ? lhs.start < rhs.start
                                    : lhs.data < rhs.data;
    });
    for (auto &a : ans) {
        if (a.end - a.start + 1 < max_width)
            continue;
        cout << a.data << " -->  x[ " << a.start << " : " << a.end + 1
             << " ]\n";
    }
    return 0;
}
