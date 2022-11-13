#include <iostream>
using namespace std;

bool hasAlternatingBits(unsigned n) {
    return (n & (n >> 1)) == 0 && (n & (n >> 2)) == (n >> 2);
}

int main()
{
    unsigned n;
    cin >> n;

    if(n < 0 || n > 4294967295){
        cout << "-1";
        return 0;
    }

    if(hasAlternatingBits(n)) cout << "true";
    else cout << "false";

    return 0;
}