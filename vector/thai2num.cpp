#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> word2dig = {
    {"soon", 0},      {"neung", 1},    {"song", 2},    {"sam", 3},
    {"si", 4},        {"ha", 5},       {"hok", 6},     {"chet", 7},
    {"paet", 8},      {"kao", 9},      {"et", 1},      {"yi", 2},
    {"sip", 10},      {"roi", 100},    {"phan", 1000}, {"muen", 10000},
    {"saen", 100000}, {"lan", 1000000}};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        string readings, read;
        getline(cin, readings);
        if (readings == "q") break;
        istringstream ss(readings);
        int idx = 0, comp = 0, total = 0;
        while (ss >> read) {
            if (idx & 1) {
                comp *= word2dig[read];
                total += comp;
                comp = 0;
            } else if (read == "sip") {
                comp = 10;
                idx--;
            } else comp += word2dig[read];
            idx++;
        }
        total += comp;
        cout << total << '\n';
    }
    return 0;
}
