#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int newNumber = 0, i = 1;

    do {
        int lastNumber = n % 10;
        if (lastNumber % 2 != 0) {
            newNumber += lastNumber * i;
            i *= 10;
        }
        n /= 10;
    } while (n != 0);

    if (newNumber > 0) cout << newNumber;
    else cout << '0';

    return 0;
}