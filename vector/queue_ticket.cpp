#include <cmath>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct order {
    int code;
    int time_stamp;
};

int main(int argc, const char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int action, total_time = 0, wait_count = 0;
    cin >> action;
    int val, current_place;
    string cmd;
    queue<order> lineup;
    order cur;
    while (action--) {
        cin >> cmd;
        if (cmd == "reset") {
            cin >> val;
            current_place = val;
        } else if (cmd == "new") {
            cin >> val;
            lineup.push({current_place, val});
            cout << ">> ticket " << current_place++ << '\n';
        } else if (cmd == "next") {
            cout << ">> call " << lineup.front().code << '\n';
            cur = lineup.front();
            lineup.pop();
        } else if (cmd == "order") {
            cin >> val;
            cout << ">> qtime " << cur.code << ' ' << (val - cur.time_stamp)
                 << '\n';
            wait_count++;
            total_time += val - cur.time_stamp;
        } else if (cmd == "avg_qtime") {
            cout << ">> avg_qtime "
                 << (round(total_time * 100.0 / wait_count) / 100.0) << '\n';
        }
    }

    return 0;
}