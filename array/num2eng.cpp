#include <iostream>
#include <string>

using namespace std;

const string deg2place[5] = {"", "thousand", "million", "billion", "trillion"};
const string dig2word[10] = {"one", "two",   "three", "four", "five",
                             "six", "seven", "eight", "nine"};
const string couple2teens[10] = {"ten",      "eleven",  "twelve",  "thirteen",
                                 "fourteen", "fifteen", "sixteen", "seventeen",
                                 "eighteen", "nineteen"};
const string tens_n_zero[8] = {"twenty", "thirty",  "forty",  "fifty",
                               "sixty",  "seventy", "eighty", "ninety"};

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string number;
    cin >> number;
    if (number == "0") {
        cout << "zero";
        return 0;
    }
    int i = (number.length() - 1) % 3;
    int deg = (number.length() - 1) / 3;

    /* 0 = unaffected
     * 1 = completely skip (when tens is '1')
     * 2 = partially affected (skip when it is '0')
     */
    int ones_state = 0;
    bool first = true;
    bool skip_place = true;
    for (auto &n : number) {
        if (i == 2 && n != '0') {
            cout << dig2word[n - '0' - 1] << " hundred ";
            skip_place = false;
        } else if (i == 1) {
            if (n - '0' > 1) {
                cout << tens_n_zero[n - '0' - 2];
                ones_state = 2;
            } else if (n == '1') ones_state = 1;
            else ones_state = 0;
            if (ones_state) skip_place = false;
        } else {
            if (ones_state != 1 && n != '0') {
                if (ones_state == 2) cout << ' ';
                cout << dig2word[n - '0' - 1];
                skip_place = false;
            } else if (ones_state == 1) {
                cout << couple2teens[n - '0'];
                skip_place = false;
            }
            ones_state = 0;
        }
        // every 3rd place
        if (i == 0) {
            if (!skip_place) cout << ' ' << deg2place[deg] << ' ';
            deg--;
            skip_place = true;
        }
        i--;
        if (i < 0) i = 2;
    }
    return 0;
}
