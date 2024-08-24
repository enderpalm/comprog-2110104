#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct station {
    string name;
    int distance;
};

unordered_map<string, vector<string>> connections;
set<string> dest;

int main(int argc, const char **argv) {
    string dst, src;
    while (getline(cin, dst)) {
        int sep = dst.find(' ');
        src = dst.substr(0, sep);
        if (sep == string::npos)
            break;
        dst = dst.substr(sep + 1);
        connections[src].push_back(dst);
        connections[dst].push_back(src);
    }

    queue<station> station_q;
    station_q.push({src, 0});
    dest.insert(src);
    while (!station_q.empty()) {
        station cur = station_q.front();
        station_q.pop();
        if (cur.distance > 1)
            continue;
        for (auto &s : connections[cur.name]) {
            dest.insert(s);
            station_q.push({s, cur.distance + 1});
        }
    }
    for (auto &s : dest)
        cout << s << '\n';
    return 0;
}