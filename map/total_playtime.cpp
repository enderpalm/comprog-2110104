#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int time2sec(string time) {
    int sep = time.find(':');
    return 60 * stoi(time.substr(0, sep)) + stoi(time.substr(sep + 1));
}

string sec2time(int sec) {
    return to_string(sec / 60) + ':' + to_string(sec % 60);
}

unordered_map<string, int> genre2sec;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i = 0;
    string raw;
    string genre;
    while (cin >> raw) {
        if (i == 2)
            genre = raw;
        else if (i == 3)
            genre2sec[genre] += time2sec(raw);

        // incrementing
        if (i == 3)
            i = 0;
        else
            i++;
    }

    vector<pair<string, int>> ans;
    ans.reserve(genre2sec.size());
    for (auto &g : genre2sec) {
        ans.push_back(g);
    }
    sort(ans.begin(), ans.end(),
         [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
             return lhs.second > rhs.second;
         });
    for (int i = 0; i < 3 && i < ans.size(); i++) {
        cout << ans[i].first << " --> " << sec2time(ans[i].second) << '\n';
    }
    return 0;
}
