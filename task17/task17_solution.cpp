#include <iostream>
using namespace std;

int length(const char str[]) {
    int size = 0;

    for(int i = 0; i < 1000; i++) {
        if(str[i] == '\0') break;
        size++;
    }

    return size;
}

void replace(char text[], const char str1[], const char str2[]) {
    if (length(text) == 0) {
        cout << "-2";
        return ;
    }

    int k = length(text);
    int n = length(str1);
    int m = length(str2);

    int count = 0;
    char final[1000];

    for (int i = 0; i < k; i++) {
        int found = 0;

        for (int j = 0; j < n; j++) {
            final[i + j] = text[i + j];
            if (text[i + j] == str1[j])
                found++;
        }
        if (found == n) {
            count++;

            if (n == m) {
                for (int j = 0; j < m; j++) {
                    final[i + j] = str2[j];
                }
            }

            if (n != m) {
                for (int j = 0; j < 1000; j++)
                    final[i + j + m] = text[i + j + n];
                for (int j = 0; j < m; j++)
                    final[i + j] = str2[j];
                for (int j = 0; j < 1000; j++)
                    text[j] = final[j];
            }

            i += m - 1;
        }
    }

    cout << count << endl;
    if (count > 0)
        cout << final << endl;
}

int main() {
    char text[1000], str1[1000], str2[1000];
    cin.getline(text, 1000);
    cin.getline(str1, 1000);
    cin.getline(str2, 1000);

    replace(text, str1, str2);

    return 0;
}