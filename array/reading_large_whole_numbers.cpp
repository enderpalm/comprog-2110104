#include <iostream>
#include <string>

using namespace std;

string dig2word[10] = {"zero", "one", "two",   "three", "four",
                       "five", "six", "seven", "eight", "nine"};

string deg2thousand[4] = {" thousand", " million", " billion", " trillion"};
string digpair2teen[10] = {"ten",      "eleven",  "twelve",  "thirteen",
                           "fourteen", "fifteen", "sixteen", "seventeen",
                           "eighteen", "nineteen"};

string dig2tens[8] = {"twenty", "thirty",  "forty",  "fifty",
                      "sixty",  "seventy", "eighty", "ninety"};

int main(int argc, const char **argv) {
    string numeral;
    cin >> numeral;
    int group = 3 - (numeral.length() % 3);
    int deg = (numeral.length() - 1) / 3 - 1;
    cout << deg << '\n';
    for (int i = 0; i < numeral.length(); i++) {

        int n = numeral[i] - '0';
      
        if (group == 0 && n)
            cout << dig2word[n] << " hundred";
        else if (group == 1 && n == 1) {
            cout << digpair2teen[numeral[i + 1] - '0'];
            group = 0;
        }
        else if (group == 1 && n > 1)
            cout << dig2tens[n - 2];
        else if (group == 2 && n != 0 && (numeral[i - 1] != '1'))
            cout << dig2word[n];

          // cout << numeral[i];
        if (group == 2 && deg >= 0) {
            cout << deg2thousand[deg];
            deg--;
        }
        if (i != numeral.length() - 1) cout << ' ';
        group++;
        if (group > 2)
            group -= 3;
    }
    return 0;
}