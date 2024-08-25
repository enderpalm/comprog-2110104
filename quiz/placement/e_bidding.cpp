#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

// bidder info in each prod bucket
struct bidding {
    int price;
    int priority;
};

struct winner {
    string prod;
    string bidder;
    bidding detail;
};

unordered_map<string, unordered_map<string, bidding>> bid_bucket;
map<string, pair<int, set<string>>> bidder2prod;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        char opcode;
        string bidder, prod;
        cin >> opcode;
        if (opcode == 'B') {
            int price;
            cin >> bidder >> prod >> price;
            bid_bucket[prod][bidder] = {price, q};
            bidder2prod[bidder] = {0, {}};
        } else if (opcode == 'W') {
            cin >> bidder >> prod;
            if (bid_bucket.find(prod) == bid_bucket.end())
                continue;
            if (bid_bucket[prod].find(bidder) == bid_bucket[prod].end())
                continue;
            bid_bucket[prod].erase(bidder);
        }
    }
    for (auto &prod : bid_bucket) {
        if (prod.second.empty())
            continue;
        winner win = {"", "", -1, -1};
        // find winner for each product
        for (auto &bidder : prod.second) {
            if ((bidder.second.price > win.detail.price) ||
                (bidder.second.price == win.detail.price &&
                 bidder.second.priority > win.detail.priority))
                win = {prod.first, bidder.first, bidder.second.price,
                       bidder.second.priority};
        }
        auto &bidder = bidder2prod[win.bidder];
        bidder.first += win.detail.price;
        bidder.second.insert(win.prod);
    }
    for (auto &bidder : bidder2prod) {
        cout << bidder.first << ": $" << bidder.second.first;
        if (!bidder.second.second.empty()) {
            cout << " ->";
            for (auto &prod : bidder.second.second)
                cout << ' ' << prod;
        }
        cout << '\n';
    }
    return 0;
}
