#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, set<string>> people2place;
vector<string> lineup;

bool has_common_place(string &person_a, string &person_b) {
    for (auto &p : people2place[person_a]) {
        if (people2place[person_b].find(p) != people2place[person_b].end())
            return true;
    }
    return false;
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string person, place;
    while (n--) {
        cin >> person;
        lineup.push_back(person);
        while (cin >> place) {
            if (place == "*")
                break;
            people2place[person].insert(place);
        }
    }
    cin >> person;
    bool not_found = true;
    for (auto &p : lineup) {
        if (p != person && has_common_place(person, p)) {
            cout << ">> " << p << '\n';
            not_found = false;
        }
    }
    if (not_found)
        cout << ">> Not Found";
    return 0;
}
