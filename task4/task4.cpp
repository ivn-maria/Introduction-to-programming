#include <iostream>
using namespace std;

int main() {
    const int radius = 4, mediumCircleRadius = radius / 2, smallCircleRadius = radius / 4;

    double x, y;
    cin >> x >> y;

    if (x > 4 || x < -4 || y > 4 || y < -4) {
        cout << "Outside";
        return 0;
    }

    if (y * y + (x - mediumCircleRadius) * (x - mediumCircleRadius) == smallCircleRadius * smallCircleRadius ||
        y * y + (x + mediumCircleRadius) * (x + mediumCircleRadius) == smallCircleRadius * smallCircleRadius ||
        y * y + (x - mediumCircleRadius) * (x - mediumCircleRadius) == mediumCircleRadius * mediumCircleRadius ||
        y * y + (x + mediumCircleRadius) * (x + mediumCircleRadius) == mediumCircleRadius * mediumCircleRadius ||
        x * x + y * y == radius * radius || x == 4 || x == -4 || y == 4 || y == -4) {
        cout << "Undefined";
        return 0;
    }

    bool small_left_x = y * y + (x - mediumCircleRadius) * (x - mediumCircleRadius) < smallCircleRadius * smallCircleRadius;
    bool small_right_x = y * y + (x + mediumCircleRadius) * (x + mediumCircleRadius) < smallCircleRadius * smallCircleRadius;
    bool medium_left_x = y * y + (x - mediumCircleRadius) * (x - mediumCircleRadius) < mediumCircleRadius * mediumCircleRadius;
    bool medium_right_x = y * y + (x + mediumCircleRadius) * (x + mediumCircleRadius) < mediumCircleRadius * mediumCircleRadius;

    if (x * x + y * y < radius * radius) {
        if (y < 0) {
            if ((!small_left_x || medium_left_x) && !small_right_x) cout << "Black";
            else cout << "White";
        } else {
            if ((!small_right_x || medium_right_x) && !small_left_x) cout << "White";
            else cout << "Black";
        }
    } else cout << "White";

    return 0;
}