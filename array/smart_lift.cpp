#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct travel {
    int src;
    int dst;

  public:
    int dir() {
        if (this->src == this->dst)
            return 0;
        return src < dst ? 1 : -1;
    }
};

struct lift {
    int num;
    travel trav;
};

int calc_cost(travel &elevator, travel &user) {
    if (elevator.dir() == user.dir() &&
        elevator.src * elevator.dir() <= user.src * user.dir()) {
        if (elevator.dst * elevator.dir() >= user.dst * user.dir())
            return 0;
        else
            return abs(user.dst - elevator.dst);
    }
    return abs(elevator.dst - user.src) + abs(user.dst - user.src);
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, src, dst;
    cin >> n;
    vector<lift> elevator_list;
    elevator_list.resize(n);
    for (auto &e : elevator_list) {
        cin >> n >> src >> dst;
        e = {n, {src, dst}};
    }
    cin >> n;
    while (n--) {
        cin >> src >> dst;
        int best_cost = INT_MAX;
        int best_lift = INT_MAX;
        travel user = {src, dst};
        for (auto &li : elevator_list) {
            int cost = calc_cost(li.trav, user);
            if (cost < best_cost || (cost == best_cost && li.num < best_lift)) {
                best_cost = cost;
                best_lift = li.num;
            }
        }
        cout << ">> " << best_lift << '\n';
    }
    return 0;
}
