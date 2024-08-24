#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double score;
    string grade = "FFFFFDCBAAA";
    cin >> score;
    cout << grade[floor(score / 10)];
    return 0;
}
