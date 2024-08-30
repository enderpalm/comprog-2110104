#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string rev_sum = "0", operand;
    while (cin >> operand) {
        if (operand == "END") break;
        int sum_idx = 0, opr_idx = operand.length() - 1, prev = 0;
        while (sum_idx < rev_sum.length() || opr_idx >= 0) {
            if (sum_idx < rev_sum.length()) prev += rev_sum[sum_idx] - '0';
            if (opr_idx >= 0) prev += operand[opr_idx] - '0';
            if (sum_idx < rev_sum.length())
                rev_sum[sum_idx] = (prev % 10) + '0';
            else rev_sum.push_back((prev % 10) + '0');
            prev /= 10;
            sum_idx++;
            opr_idx--;
        }
        if (prev != 0) rev_sum.push_back(prev + '0');
    }
    for (int i = rev_sum.length() - 1; i >= 0; i--)
        cout << rev_sum[i];
    return 0;
}
