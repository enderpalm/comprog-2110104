#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct student {
    string code;
    float score;
    string choose[4];
};

unordered_map<string, int> dept2quota;
vector<student> std_list;

int main(int argc, const char **argv) {
    int n, m;
    string t_dept;
    int t_quota;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> t_dept >> t_quota;
        dept2quota[t_dept] = t_quota;
    }

    cin >> m;
    std_list.resize(m);
    for (int i = 0; i < m; i++) {
        student student;
        cin >> student.code >> student.score;
        for (int j = 0; j < 4; j++)
            cin >> student.choose[j];
        std_list[i] = student;
    }

    sort(std_list.begin(), std_list.end(), [](student &left, student &right) {
        return left.score > right.score;
    });
    for (auto &s : std_list) {
        for (int i = 0; i < 4; i++) {
            if (dept2quota[s.choose[i]] > 0) {
                s.choose[0] = s.choose[i];
                dept2quota[s.choose[i]]--;
                break;
            }
        }
    }

    sort(std_list.begin(), std_list.end(),
         [](student &left, student &right) { return left.code < right.code; });
    for (auto s : std_list) {
        cout << s.code << ' ' << s.choose[0] << '\n';
    }

    return 0;
}