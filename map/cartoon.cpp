#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<string>> cate2name;
vector<string> line_up;

int main(int argc, const char **argv) {
    string name, type;
    while (cin >> name >> type) {
        cate2name[type].push_back(name);
        if (find(line_up.begin(), line_up.end(), type) == line_up.end())
            line_up.push_back(type);
    }

    bool first = true;
    for (auto &cate : line_up) {
        if (!first)
            cout << '\n';
        else
            first = false;
        cout << cate << ": ";
        for (auto &cha : cate2name[cate])
            cout << cha << ' ';
    }
    return 0;
}