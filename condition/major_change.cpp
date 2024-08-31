#include <iostream>
#include <string>

using namespace std;

struct student {
    string code;
    float gpax;
    char comprog;
    char cal1;
    char cal2;
};

bool first_qualify(student &spec) {
    return spec.comprog == 'A' && spec.cal1 <= 'C' && spec.cal2 <= 'C';
}

int choose(student &A, student &B) {
    if (A.gpax == B.gpax && A.cal1 == B.cal1 && A.cal2 == B.cal2) return 2;
    if (A.gpax == B.gpax) {
        if (A.cal1 == B.cal1) return A.cal2 < B.cal2 ? 0 : 1;
        else return A.cal1 < B.cal1 ? 0 : 1;
    }
    return A.gpax > B.gpax ? 0 : 1;
}

int main(int argc, const char **argv) {
    student std_list[2];
    for (int i = 0; i < 2; i++) {
        cin >> std_list[i].code >> std_list[i].gpax >> std_list[i].comprog >>
            std_list[i].cal1 >> std_list[i].cal2;
    }

    if (!first_qualify(std_list[0]) && !first_qualify(std_list[1]))
        cout << "None";
    else if (!first_qualify(std_list[0])) cout << std_list[1].code;
    else if (!first_qualify(std_list[1])) cout << std_list[0].code;
    else {
        int res = choose(std_list[0], std_list[1]);
        cout << (res == 2 ? "Both" : std_list[res].code);
    }
    return 0;
}