#include <iostream>
using namespace std;

int longestDist(const int arr[], const int arrSize) {
    if (arrSize < 2) {
        cout << "-2";
        return 0;
    }

    int dist = 0,check = 0;

    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[i] == arr[j] && (j - i) > dist) {
                dist = (j - i);
                check = i;
            }
        }
    }

    if(dist == 0) cout << "-1";
    else cout << check;
}

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 100) {
        cout << "-1";
        return 0;
    }

    int myArr[N];

    for (int i = 0; i < N; i++)
        cin >> myArr[i];

    longestDist(myArr, N);

    return 0;
}
