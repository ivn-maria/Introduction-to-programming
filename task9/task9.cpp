#include <iostream>
using namespace std;

int nArr[20], kArr[20];

void swapNumbers(int x, int y) {
    int operations = 0;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (nArr[i] == kArr[j] && i != j) {
                int temp = nArr[i];
                nArr[i] = nArr[j];
                nArr[j] = temp;
                operations++;
            }
        }
    }

    if (operations == 0) operations += x + y;
    else{
        while (x < y) {
            x++;
            operations++;
        }

        while (x > y) {
            x--;
            operations++;
        }
    }

    cout << operations << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;

    if (n < 0 || k < 0) {
        cout << "-1";
        return 0;
    }

    int nLength = 0, kLength = 0;

    for (int i = n; i > 0; i /= 10)
        nLength++;

    for (int i = nLength - 1; i >= 0; i--) {
        nArr[i] = n % 10;
        n /= 10;
    }

    for (int i = k; i > 0; i /= 10)
        kLength++;

    for (int i = kLength - 1; i >= 0; i--) {
        kArr[i] = k % 10;
        k /= 10;
    }

    swapNumbers(nLength, kLength);

    return 0;
}