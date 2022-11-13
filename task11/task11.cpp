#include <iostream>
using namespace std;

int wordsize(const char word[]) {
    int length = 0;

    for(int i = 0; i < 20; i++) {
        if(word[i] == '\0')
            break;
        length++;
    }

    return length;
}

bool isCorrect(const char sequence[][20], int sequencesize) {
    for (int i = 0; i < sequencesize - 1; i++) {
        int matches = 0, fix = 0;

        for (int j = 0; j < wordsize(sequence[i]); j++) {
            if(sequence[i][j] == sequence[i+1][fix]) {
                fix++;
                matches++;
            }
            if (sequence[i][j] == sequence[i+1][j]) {
                fix++;
                matches++;
            }
        }

        if (wordsize(sequence[i]) > matches+1 || wordsize(sequence[i+1]) > matches+1)
            return false;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    if (N < 2 || N > 50) {
        cout << "-1";
        return 0;
    }

    char words[50][20];

    for (int i = 0; i < N; i++)
        cin >> words[i];

    if(isCorrect(words, N))cout << "True";
    else cout << "False";

    return 0;
}