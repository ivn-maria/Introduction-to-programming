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

void longestSubstrWithUniqueSymbolsLength(const char str[]) {
    if (strsize(str) == 1){
        cout << 1;
        return;
    }

    int len = 0, check = 0;

    for (int i = 0; i < strsize(str); i++) {
        if (str[i] != str[i+1]) {
            len++;

            for (int j = i - len + 1; j < i; j++) {
                if (str[i+1] == str[j]) {
                    len--;
                    check = len + 1;
                }
            }

            if(check < i - len)
                len = 0;
        }
        else if(len >= check) {
            check = len + 1;
            len = 0;
        }
    }

    cout << check;
}

int main() {
    char arr[100];
    cin.getline(arr, 100);

    longestSubstrWithUniqueSymbolsLength(arr);

    return 0;
}