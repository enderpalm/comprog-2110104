#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char **argv) {
    int n, m, op;
    cin >> n >> m;
    map<string, string> per2dep;
    map<string, set<string>> dep2per;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        per2dep[a] = b;
        dep2per[b].insert(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> op;
        switch (op) {
        case 1: {
            cin >> a >> b;
            if (per2dep[a] == b)
                break;
            dep2per[b].insert(a);
            dep2per[per2dep[a]].erase(a);
            per2dep[a] = b;
            break;
        }
        case 2: {
            cin >> a >> b;
            for (auto e = dep2per[a].begin(); e != dep2per[a].end(); e++) {
                per2dep[*e] = b;
                dep2per[b].insert(*e);
            }
            dep2per.erase(a);
            break;
        }
        }
    }
    for (auto d : dep2per) {
        cout << d.first << ": ";
        for (auto e : d.second)
            cout << e << " ";
        cout << '\n';
    }
    return 0;
}