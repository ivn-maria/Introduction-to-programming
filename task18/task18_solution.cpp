#include <iostream>
using namespace std;

int beginning = 0;

int isHacksaw(int str[], int size) {
    if (beginning == size - 2) {
        cout << "yes";
        return 0;
    }

    bool bigger;
    if (str[beginning] > str[beginning + 1])
        bigger = true;
    else bigger = false;

    if (bigger) {
        if (str[beginning + 1] < str[beginning + 2]) {
            beginning++;
            isHacksaw(str, size);
        }
        else cout << "no";
    }

    if (!bigger) {
        if (str[beginning + 1] > str[beginning + 2]) {
            beginning++;
            isHacksaw(str, size);
        }
        else cout << "no";
    }

    return 0;
}

int main() {
    int N;
    cin >> N;

    if (N < 3 || N > 1000) {
        cout << "-1";
        return 0;
    }

    int n[N];
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    isHacksaw(n, N);

    return 0;
}