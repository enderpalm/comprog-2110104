#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct group {
    int remaining = 100;
    vector<int> grp;
};

vector<group> ans;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr;
    int tmp;
    string opcode;
    cin >> opcode;
    while (cin >> tmp)
        arr.push_back(tmp);

    if (opcode == "first") {
        for (auto &e : arr) {
            bool free = true;
            for (auto &g : ans) {
                if (g.remaining < e)
                    continue;
                g.grp.push_back(e);
                g.remaining -= e;
                free = false;
                break;
            }
            if (free)
                ans.push_back({100 - e, {e}});
        }
    }

    else if (opcode == "best") {
        for (auto &e : arr) {
            bool free = true;
            int least_remain_val = 101;
            int least_remain_idx = 0;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i].remaining < e)
                    continue;
                if (least_remain_val > ans[i].remaining - e) {
                    least_remain_val = ans[i].remaining - e;
                    least_remain_idx = i;
                }
                free = false;
            }
            if (free)
                ans.push_back({100 - e, {e}});
            else {
                ans[least_remain_idx].grp.push_back(e);
                ans[least_remain_idx].remaining -= e;
            }
        }
    }

    for (auto &e : ans)
        sort(e.grp.begin(), e.grp.end());

    sort(ans.begin(), ans.end(), [](const group &lhs, const group &rhs) {
        if (lhs.remaining != rhs.remaining)
            return lhs.remaining < rhs.remaining;
        if (lhs.grp.size() != rhs.grp.size())
            return lhs.grp.size() < rhs.grp.size();
        for (int i = 0; i < lhs.grp.size(); i++) {
            if (lhs.grp[i] != rhs.grp[i])
                return lhs.grp[i] < rhs.grp[i];
        }
        return false;
    });

    for (auto &e : ans) {
        for (auto &g : e.grp)
            cout << g << ' ';
        cout << '\n';
    }
    return 0;
}
