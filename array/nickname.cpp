#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> real2nick = {
    {"Robert", "Dick"},   {"William", "Bill"},   {"James", "Jim"},
    {"John", "Jack"},     {"Margaret", "Peggy"}, {"Edward", "Ed"},
    {"Sarah", "Sally"},   {"Andrew", "Andy"},    {"Anthony", "Tony"},
    {"Deborah", "Debbie"}};
unordered_map<string, string> nick2real = {
    {"Dick", "Robert"},   {"Bill", "William"},   {"Jim", "James"},
    {"Jack", "John"},     {"Peggy", "Margaret"}, {"Ed", "Edward"},
    {"Sally", "Sarah"},   {"Andy", "Andrew"},    {"Tony", "Anthony"},
    {"Debbie", "Deborah"}};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string tmp;
    while (n--) {
        cin >> tmp;
        if (real2nick.find(tmp) != real2nick.end()) cout << real2nick[tmp];
        else if (nick2real.find(tmp) != nick2real.end()) cout << nick2real[tmp];
        else cout << "Not found";
        cout << '\n';
    }
    return 0;
}
