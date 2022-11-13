#include <iostream>
using namespace std;

void printPassword(int password[]) {
    cout << (char) password[0] << (char) password[1] << password[2];
    cout << password[3] << (char) password[1] << (char) password[0] << '|';
}

int genPassword(int x, int y, int numbOfPass) {
    int password[100] = {35, 64, 1, 1};

    for(int i = 1; i <= x; i++) {
        password[2] = i;

        for(int j = 1; j <= y; j++) {
            if (numbOfPass == 0)
                return 0;

            password[3] = j;

            printPassword(password);
            numbOfPass--;

            password[0] += 1;
            password[1] += 1;

            if(password[0] == 56)
                password[0] = 35;
            if(password[1] == 97)
                password[1] = 64;
        }
    }

    return 0;
}

int main() {
    int a, b ,c;
    cin >> a >> b >> c;

    genPassword(a, b, c);

    return 0;
}