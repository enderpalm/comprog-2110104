#include <iostream>
using namespace std;

int main(int argc, const char **argv) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x < 50) {
        while (true) {
            if (y <= z) goto print;
            if (y & 1) {
                x -= y - z;
                y++;
                continue;
            }
            x += y * y + z * z;
            if (x % 10 == 4) goto print;
            if (x % 3 == 0) y--;
            else z++;
            if (x / (y + z) > 15) goto print;
        }
    } else {
        if (x > y) {
            if (!(x & 1)) {
                x *= 2;
                y = x + 4;
                z = (y - x) * 3;
            } else if (y < z) {
                x += y;
                y = x * 3;
                z += y;
            } else {
                x >>= 1;
                y <<= 1;
                z = x - y;
            }
            goto print;
        }
        if (z % 3 == 2) {
            x = y * 5;
            y = x >> 1;
            z = y + 7;
        } else if (y > z) {
            x += z;
            y -= 3;
            z = x << 1;
        } else {
            x--;
            y += z;
            z = y - 4;
        }
    }
print:
    cout << x << ' ' << y << ' ' << z;
    return 0;
}