#include <iostream>
using namespace std;

int strsize(const char word[]) {
    int length = 0;

    for (int i = 0; i < 20; i++) {
        if(word[i] == '\0') break;

        length++;
    }

    return length;
}

int isRelevant(const char str[], char strsmalls[], char strcapitals[]) {
    int j = 0, k = 0;

    for (int i = 0; i < strsize(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            strcapitals[j] = str[i];
            j++;
        }
        else {
            strsmalls[k] = str[i];
            k++;
        }
    }

    int relevants = 0;

    if (strsize(strcapitals) != strsize(strsmalls)) return false;
    else {
        for (int i = 0; i < strsize(strcapitals); i++) {
            if (strsmalls[i] - strcapitals[i] == 32)
                relevants++;
        }

        if (relevants == strsize(strcapitals))
            return true;
        else return false;
    }
}

int main() {
    char X[255], s[255] = {'\0'}, S[255] = {'\0'};
    cin.getline(X, 255);

    for (int i = 0; i < strsize(X); i++) {
        if (X[i] < 'A' || (X[i] > 'Z' && X[i] < 'a') || X[i] > 'z') {
            cout << "-1";
            return 0;
        }
    }

    if (isRelevant(X, s, S)) cout << "Yes";
    else cout << "No";

    return 0;
}