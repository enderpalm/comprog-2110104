#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> name2tel;
unordered_map<string, string> tel2name;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    name2tel.reserve(n);
    tel2name.reserve(n);
    while (n--) {
        string raw;
        getline(cin, raw);
        int last_space = raw.find_last_of(' ');
        string name = raw.substr(0, last_space);
        raw = raw.substr(last_space + 1);
        name2tel[name] = raw;
        tel2name[raw] = name;
    }
    cin >> n;
    cin.ignore();
    while (n--) {
        string query;
        getline(cin, query);
        cout << query << " --> ";
        if (name2tel.find(query) != name2tel.end())
            cout << name2tel[query] << '\n';
        else if (tel2name.find(query) != tel2name.end())
            cout << tel2name[query] << '\n';
        else cout << "Not found" << '\n';
    }
    return 0;
}
