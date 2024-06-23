#include <iostream>

using namespace std;

int main() {
    
    int a = 10;
    int &r = a;
    r = 25;
    
    int b = 30;
    r = b; // Value 30 is stored in r, so 30 is stored in a, r means a itself.
    
    cout << a << endl << r << endl;
    return 0;
}