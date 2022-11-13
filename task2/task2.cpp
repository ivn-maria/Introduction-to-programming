#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int a = N, a_reversed = 0, lastNumber, length = 0;

    if (N <= 1 || N >= 1000000000){
        cout << "-1";
        return 0;
    }

    while (N != 0) {
        lastNumber = N % 10;
        a_reversed = a_reversed * 10 + lastNumber;
        N /= 10;
        length ++;
    }

    for (int i = 0; i < length / 2 + length % 2; i++) {
        int x = a % 10;
        int y = a_reversed % 10;
        if (x > y) cout << x << ' ';
        else if (x < y) cout << y << ' ';
        else if (x == y) cout << ' ';
        a /= 10;
        a_reversed /= 10;
    }
    return 0;
}