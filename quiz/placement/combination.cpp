#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct pattern {
    string literal;
    int freq;
};

vector<string> raw;
unordered_map<string, int> pattern2freq;

int n, m;

void permute(int idx, string &cur) {
    if (idx == n) {
        string cpy = cur;
        sort(cpy.begin(), cpy.end());
        pattern2freq[cpy]++;
        return;
    }
    for (int i = 0; i < raw[idx].length(); i++) {
        cur.push_back(raw[idx][i]);
        permute(idx + 1, cur);
        cur.pop_back();
    }
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    raw.resize(n);
    for (auto &p : raw)
        cin >> p;
    string cur = "";
    permute(0, cur);
    cin >> m;
    vector<pattern> ans;
    ans.reserve(pattern2freq.size());
    for (auto &a : pattern2freq)
        ans.push_back({a.first, a.second});
    sort(ans.begin(), ans.end(), [](const pattern &lhs, const pattern &rhs) {
        return lhs.freq == rhs.freq ? lhs.literal < rhs.literal
                                    : lhs.freq > rhs.freq;
    });
    for (int i = 0; i < ans.size() && i < m; i++)
        cout << ans[i].literal << '\n';
    return 0;
}
