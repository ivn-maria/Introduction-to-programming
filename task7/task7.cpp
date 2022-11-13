#include <iostream>
using namespace std;

bool isPalindrome(int N){
    if(N < 100)
        return false;

    int reversedN = 0, lastDigit, checkN = N;

    while (checkN != 0) {
        lastDigit = checkN % 10;
        reversedN = reversedN * 10 + lastDigit;
        checkN /= 10;
    }

    if (N == reversedN) return true;
    else return false;
}

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 1000000000) {
        cout << "-1";
        return 0;
    }

    if (isPalindrome(N)) {
        cout << N;
        return 0;
    }

    if (!isPalindrome(N)) {
        int NMinus = N -1, NPlus = N + 1;

        while (!isPalindrome(NMinus) && N > 99)
            NMinus -= 1;

        while (!isPalindrome(NPlus))
            NPlus += 1;

        if ((N - NMinus) <= (NPlus - N) && N > 99) cout << NMinus;
        else cout << NPlus;
    }

    return 0;
}
