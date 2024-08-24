#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, set<int>> warp;
bool possible = false;

void travel(vector<int>& path, int cur, int dest) {
    if (cur == dest) {
        possible = true;
        if (!path.empty()) cout << path[0];
        for (int i = 1; i < path.size(); i++) cout << " -> " << path[i];
        cout << '\n';
        return;
    }
    if (warp.find(cur) == warp.end()) return;
    for (auto neighbor : warp[cur]) {
        path.push_back(neighbor);
        travel(path, neighbor, dest);
        path.pop_back();
    }
}

int main(int argc, const char** argv) {
    int w, a, b, tmpa, tmpb;
    cin >> w >> a >> b;
    for (int i = 0; i < w; i++) {
        cin >> tmpa >> tmpb;
        warp[tmpa].insert(tmpb);
    }
    vector<int> path;
    path.push_back(a);
    travel(path, a, b);
    if (!possible) cout << "no";
    return 0;
}