#include <iostream>
#include <istream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> front2rear;
unordered_map<string, string> rear2front;

int main(int argc, const char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        front2rear[a] = b;
        rear2front[b] = a;
    }
    cin >> m;
    while (m--) {
        cin >> a;
        if (front2rear.find(a) != front2rear.end())
            cout << front2rear[a] << '\n';
        else if (rear2front.find(a) != rear2front.end())
            cout << rear2front[a] << '\n';
        else
            cout << "Not found" << '\n';
    }
    return 0;
}