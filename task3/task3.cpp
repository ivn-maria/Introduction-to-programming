#include <iostream>
using namespace std;

int main(){
    int n, salary;
    cin >> n >> salary;

    char website;

    if (n < 1 || n > 10 || salary < 700 || salary > 1500) {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> website;

        if (website == 'F') salary -= 150;
        if (website == 'I') salary -= 100;
        if (website == 'R') salary -= 50;
        if (website == 'd') continue;
        if (salary <= 0) break;
    }

    if (salary > 0) cout << salary;
    else cout << "You have lost your salary.";

    return 0;
}