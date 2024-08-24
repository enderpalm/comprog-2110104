#include <iostream>
#include <sstream>
#include <string>

using namespace std;

char next_valid(char prev) {
    switch (prev) {
    case 'R':
        return 'Y';
    case 'Y':
        return 'G';
    case 'G':
        return 'N';
    case 'N':
        return 'B';
    case 'B':
        return 'P';
    case 'P':
        return 'K';
    case 'K':
        return '\n';
    }
    return ' ';
}

int color2score(char color) {
    switch (color) {
    case 'R':
        return 1;
    case 'Y':
        return 2;
    case 'G':
        return 3;
    case 'N':
        return 4;
    case 'B':
        return 5;
    case 'P':
        return 6;
    case 'K':
        return 7;
    }
    return ' ';
}

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    cin.ignore();
    while (q--) {
        string seq;
        getline(cin, seq);
        stringstream ss(seq);
        bool end_red = false;
        bool odd = true;
        bool wrong = false;
        char prev = 'R';
        int score = 0;
        if (seq[0] != 'R') wrong = true;
        while (ss >> seq && !wrong) {
            if (!odd && !end_red && seq == "R") wrong = true;
            if (odd && !end_red && seq != "R") end_red = true;
            if (end_red) {
                if (next_valid(prev) != seq[0]) wrong = true;
                prev = seq[0];
            }
            odd = !odd;
            score += color2score(seq[0]);
        }
        if (wrong) cout << "WRONG_INPUT\n";
        else cout << score << '\n';
    }
    return 0;
}
