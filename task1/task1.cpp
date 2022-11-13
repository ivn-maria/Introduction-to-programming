#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 9) {
        cout << "-1";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i - 1; k++)
            cout << ' ';

        for (int j = i; j <= n; j++)
            cout << j;

        cout << endl;
    }

    for (int i = n; i > 1; i--) {
        int k = 1;

        while (k != n) {
            cout << ' ';
            k++;
        }

        for (int j = n; j >= i - 1; j--)
            cout << j;

        cout << endl;
    }

    return 0;
}