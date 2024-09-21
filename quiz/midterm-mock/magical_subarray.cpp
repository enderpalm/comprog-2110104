#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, const char **argv) {
    int n, cnt = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int sub_size = r - l + 1;
            bool found[sub_size];
            memset(found, false, sub_size);
            bool is_magic = true;
            for (int i = l; i <= r && is_magic; i++) {
                if (arr[i] < 1 || arr[i] > sub_size) is_magic = false;
                else if (!found[arr[i] - 1]) found[arr[i] - 1] = true;
                else is_magic = false;
            }
            for (int i = 0; i < sub_size && is_magic; i++)
                if (!found[i]) is_magic = false;
            cnt += is_magic;
        }
    }
    cout << cnt;
    return 0;
}