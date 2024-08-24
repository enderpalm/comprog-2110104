#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct student {
    string code;
    int grade;
};

string num2letter_grade[8] = {"A", "B+", "B", "C+", "C", "D+", "D", "F"};

int letter_grade_2_num(string &grade) {
    if (grade == "F")
        return 7;
    return ((grade[0] - 'A') << 1) - (grade.length() == 2);
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string code, letter_grade;
    int n, grade;
    cin >> n;
    vector<student> student_list;
    unordered_map<string, int> code2idx;
    student_list.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> code >> letter_grade;
        student_list[i] = {code, letter_grade_2_num(letter_grade)};
        code2idx[code] = i;
    }
    while (cin >> code) {
        int idx = code2idx[code.substr(0, code.length() - 1)];
        char op = code[code.length() - 1];
        auto pos = &student_list[idx];
        if (op == '+' && pos->grade > 0)
            pos->grade--;
        else if (op == '-' && pos->grade < 7)
            pos->grade++;
    }
    sort(student_list.begin(), student_list.end(),
         [](const student &lhs, const student &rhs) {
             return lhs.grade < rhs.grade;
         });
    for (auto &st : student_list) {
        cout << st.code << ' ' << num2letter_grade[st.grade] << '\n';
    }
    return 0;
}
