#include <iostream>
#include <string>

using namespace std;

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*
123.456(789)

123 + (456789 - 456) / 999000

123 + (456333) / 999000

123 + (152111 / 333000)

((333000 * 123) + 152111) / 333000

*/

int main(int /*argc*/, const char ** /*argv*/) {
    string whole, dec, rep;
    cin >> whole >> dec >> rep;

    long denom;
    for (int i = 0; i < rep.length(); i++)
        denom = denom * 10 + 9;
    for (int i = 0; i < dec.length(); i++)
        denom *= 10;

    long numer = stol(dec + rep) - stol(dec);
    long common = gcd(numer, denom);
    numer /= common;
    denom /= common;

    numer += stol(whole) * denom;
    cout << numer << " / " << denom;
    return 0;
}
