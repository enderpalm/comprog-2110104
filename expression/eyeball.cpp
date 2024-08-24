#include <cmath>
#include <iostream>

using namespace std;

int main(int /*argc*/, const char ** /*argv*/) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x_mouse, y_mouse, x_eye, y_eye, eye_rad, pupil_rad;
    cin >> x_eye >> y_eye >> eye_rad >> pupil_rad >> x_mouse>> y_mouse;
    double x_dis = x_mouse - x_eye;
    double y_dis = y_mouse - y_eye;
    double hypo = sqrt(x_dis * x_dis + y_dis * y_dis);
    double ratio = ((double) (eye_rad - pupil_rad)) / hypo;
    x_dis *= ratio;
    y_dis *= ratio;
    cout << round(x_dis + x_eye) << ' ' << round(y_dis + y_eye);
    return 0;
}
