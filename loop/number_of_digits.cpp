#include <iostream>
#include <string>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long count = 0, start, end;
    cin >> start >> end;
    int start_length = to_string(start).length();
    int end_length = to_string(end).length();

    // front
    long long rounder = stoll(string(start_length, '9'));
    count += (rounder - start + 1) * start_length;

    // mid
    for (int i = start_length + 1; i < end_length; i++) {
        long long tmp = 9 * i;
        for (int j = 1; j < i; j++)
            tmp *= 10;
        count += tmp;
    }

    // back
    rounder = stoll("1" + string(end_length - 1, '0'));
    count += (end - rounder + 1) * end_length;

    cout << count;
    return 0;
}
