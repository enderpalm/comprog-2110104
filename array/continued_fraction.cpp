#include <iomanip>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    double arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << setprecision(10) << arr[0] << '\n';
    for (int i = 1; i < n; i++) {
        double res = arr[i];
        for (int j = i - 1; j >= 0; j--)
            res = arr[j] + 1 / res;
        ;
        cout << setprecision(10) << res << '\n';
    }
    return 0;
}
