#include <iostream>
#include <map>

using namespace std;

int H(int n) { // Tower of Hanoi
    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans << 1) + 1;
    return ans;
}

int dpc[100] = {0};

int C(int n) { // Catalan Number
    if (n == 0) return 1;
    if (dpc[n] != 0) return dpc[n];
    int res = 0;
    for (int k = 0; k <= n - 1; k++) {
        res += C(k) * C(n - k - 1);
    }
    return dpc[n] = res;
}

int M(int n);

int F(int n) { // Female sequence
    if (n == 0) return 1;
    return n - M(F(n - 1));
}

int M(int n) { // Male sequence
    if (n == 0) return 0;
    return n - F(M(n - 1));
}

int main() {
    map<string, int (*)(int)> func = {{"H", H}, {"C", C}, {"F", F}, {"M", M}};
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }

    return 0;
}