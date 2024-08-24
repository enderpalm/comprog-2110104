#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sale {
    string code;
    float price;
    float total;
};

vector<sale> sales;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string code;
    float price;
    while (cin >> code) {
        if (code == "END") {
            cin.ignore();
            break;
        }
        cin >> price;
        sales.push_back({code, price, 0});
    }
    while (cin >> code) {
        auto prod = find_if(sales.begin(), sales.end(),
                            [&code](sale &test) { return test.code == code; });
        prod->total += prod->price;
    }
    sort(sales.begin(), sales.end(), [](const sale &lhs, const sale &rhs) {
        return lhs.total == rhs.total ? lhs.code < rhs.code
                                      : lhs.total > rhs.total;
    });
    if (sales.size() == 0 || sales[0].total == 0) {
        cout << "No Sales";
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (sales[i].total == 0)
            break;
        cout << sales[i].code << ' ' << sales[i].total << '\n';
    }
    return 0;
}
