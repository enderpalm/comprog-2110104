#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> warp;

int main(int argc, const char** argv) {
    int w, a, b, tmpa, tmpb;
    cin >> w >> a >> b;
    for (int i = 0; i < w; i++) {
        cin >> tmpa >> tmpb;
        warp[tmpa].push_back(tmpb);
    }
    queue<int> roomVisit;
    roomVisit.push(a);
    while (!roomVisit.empty()) {
        int cur = roomVisit.front();
        roomVisit.pop();
        if (cur == b) {
            cout << "yes";
            return 0;
        }
        if (warp.find(cur) != warp.end()) {
            for (auto r : warp[cur]) 
                roomVisit.push(r);
        }
    }
    cout << "no";
    return 0;
}