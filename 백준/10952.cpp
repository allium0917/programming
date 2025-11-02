#include <iostream>
using namespace std;

int main() {
    bool reset = true;
    while (reset) {
        int a,b;
        cin>>a>>b;
        if (a == 0 && b == 0) {
            reset = false;
        }
        else {
            cout << a+b << endl;
        }
    }
}
