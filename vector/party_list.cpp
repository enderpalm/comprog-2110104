#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct party {
    string name;
    int score;
    int cand;
};

int main(int argc, const char **argv) {
    string party_name;
    int score;
    float total_score = 0;
    vector<party> party_list;
    while (cin >> party_name) {
        if (party_name == "END")
            break;
        cin >> score;
        total_score += score;
        party_list.push_back({party_name, score});
    }
    total_score /= 100;
    sort(party_list.begin(), party_list.end(),
         [&total_score](party &left, party &right) {
             float whole;
             return modf(static_cast<float>(left.score) / total_score, &whole) >
                    modf(static_cast<float>(right.score) / total_score, &whole);
         });

    int total_cand = 100;
    for (auto &p : party_list) {
        p.cand = static_cast<int>(p.score / total_score);
        total_cand -= p.cand;
    }
    for (int i = 0; i < total_cand; i++)
        party_list[i].cand++;

    sort(party_list.begin(), party_list.end(), [](party &left, party &right) {
        return left.cand == right.cand ? left.score > right.score
                                       : left.cand > right.cand;
    });

    for (auto &p : party_list) {
        if (p.cand == 0)
            break;
        cout << p.name << ' ' << p.cand << ' ' << p.score << '\n';
    }
    return 0;
}