#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cin >> str;

    int sum = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'C') sum += 3;
        else if (c <= 'F') sum += 4;
        else if (c <= 'I') sum += 5;
        else if (c <= 'L') sum += 6;
        else if (c <= 'O') sum += 7;
        else if (c <= 'S') sum += 8;
        else if (c <= 'V') sum += 9;
        else if (c <= 'Z') sum += 10;
    }

    cout << sum << endl;
    return 0;
}