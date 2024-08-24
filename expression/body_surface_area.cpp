#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    double w, h;
    cin >> w >> h;
    double mosteller = sqrt(w * h) / 60;
    double haycock = 0.024265 * pow(w, 0.5378) * pow(h, 0.3964);
    double boyd = 0.0333 * pow(w, 0.6157 - 0.0188 * log10(w)) * pow(h, 0.3);
    cout << setprecision(15) << mosteller << '\n' << haycock << '\n' << boyd;
    return 0;
}