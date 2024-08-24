#include <iostream>
#include <map>
#include <vector>

using namespace std;

int F(int n) { // Fibonacci number
    vector<int> dp;
    dp.resize(n + 1);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i & 1)
            dp[i] =
                dp[(i + 1) >> 1] * dp[(i + 1) >> 1] + dp[i >> 1] * dp[i >> 1];
        else
            dp[i] = dp[i >> 1] * ((dp[(i - 1) >> 1] << 1) + dp[i >> 1]);
    }
    return dp[n];
}

int M(int n) { // Motzkin number
    vector<int> dp;
    dp.resize(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = 0;
        for (int j = 0; j <= i - 2; j++)
            tmp += dp[j] * dp[i - 2 - j];
        dp[i] = dp[i - 1] + tmp;
    }
    return dp[n];
}
int S(int n) { // Schröder–Hipparchus Number
    if (n < 3)
        return 1;
    int a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++) {
        c = ((6 * i - 9) * b - (i - 3) * a) / i;
        a = b;
        b = c;
    }
    return c;
}
int D(int n) { // Derangement
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
        if (i & 1)
            res--;
        else
            res++;
    }
    return res;
}

int main() {
    map<string, int (*)(int)> func = {{"F", F}, {"M", M}, {"S", S}, {"D", D}};
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }
    return 0;
}