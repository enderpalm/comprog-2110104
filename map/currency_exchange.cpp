#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, float> cur2ex;

int main(int argc, const char **argv) {
    int n;
    cin >> n;
    cur2ex.reserve(n + 1);
    cur2ex["THB"] = 1;
    while (n--) {
        string cur;
        float ex;
        cin >> cur >> ex;
        cur2ex[cur] = ex;
    }
    cin.ignore();
    string query;
    getline(cin, query);
    short first_space = query.find_first_of(' ');

    int amount = stoi(query.substr(0, first_space));
    query = query.substr(first_space);
    string prev_currency = query.substr(1, 3);
    cout << amount << ' ' << prev_currency;

    for (int i = 5; i + 2 < query.length(); i += 4) {
        string cur_currency = query.substr(i, 3);
        amount = (int)(amount * cur2ex[prev_currency] / cur2ex[cur_currency]);
        cout << " -> " << amount << ' ' << cur_currency;
        prev_currency = cur_currency;
    }
    return 0;
}