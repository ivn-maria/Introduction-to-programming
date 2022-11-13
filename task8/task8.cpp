#include <iostream>
using namespace std;

int calculator(int x, int y) {
    int ans = 0;

    while (y > x) {
        ans++;
        if (y % 2 == 1) y++;
        else y /= 2;
    }

    return ans + x - y;
}

int main()
{
    int x, y;
    cin >> x >> y;

    if (x < 0 || y < 0) {
        cout << "-1";
        return 0;
    }

    cout << calculator(x, y);

    return 0;
}