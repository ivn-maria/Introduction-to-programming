#include <iostream>
using namespace std;

int length (const char str[]) {
    int size = 0;

    for (int i = 0; i < 20; i++) {
        if(str[i] == '\0') break;
        size++;
    }

    return size;
}

char* copy(char* secondStr, const char* firstStr) {
    int size = length(firstStr);

    for (int i = 0; i < size; i++)
        secondStr[i] = firstStr[size-1-i];
    secondStr[size] = '\0';

    return nullptr;
}

int countPermutations (char* str) {
    int countLetters = 0;
    for (int i = 0; i < length(str); i ++) {
        if (str[i] > 96 && str[i] < 123) {
            countLetters++;
        }
    }

    int count = 1;
    for(int i = 0; i < countLetters; i ++)
        count *= 2;

    return count;
}

int sortLexicographical (char* str, char matrix[][50]) {
    char temp;
    for (int i = 0; i < countPermutations(str) - 1; i++){
        for (int j = i + 1; j < countPermutations(str); j++) {
            for (int l = length(str) - 1; l >= 0; l--) {
                if (matrix[i][l] == matrix[j][l] - 32) {
                    for (int k = 0; k < length(str); k++) {
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                }
            }
        }
    }

    return 0;
}

int numberOfPermutation = 0;

char** getPermutation(char* str, char matrix[][50], int beginning) {
    char str1[50];
    copy(str1, str);

    for (int i = beginning; i < length(str); i++) {
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
            numberOfPermutation++;
            for (int j = 0; j < length(str); j++)
                matrix[numberOfPermutation][j] = str[j];
            beginning++;
            getPermutation(str, matrix, beginning);
            copy(str, str1);
        }
    }

    return nullptr;
}

char** letterCasePermutation(char* str) {
    char matrix[50][50];
    for (int i = 0; i < length(str); i++)
        matrix[0][i] = str[i];

    getPermutation (str, matrix, 0);
    sortLexicographical (str, matrix);

    for (int i = 0; i < countPermutations(str); i++) {
        for(int j = 0; j < length(str); j++)
            cout << matrix[i][j];
        cout << endl;
    }

    return nullptr;
}

int main() {
    char arr[50];
    cin.getline (arr, 50);

    letterCasePermutation(arr);

    return 0;
}