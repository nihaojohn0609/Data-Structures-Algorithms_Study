#include <iostream>

using namespace std;

int main() {
    int length = 0, breadth = 0;

    printf("Enter Length and Breadth:\n");
    cin >> length >> breadth;
    
    int area = length * breadth;
    int peri = 2 * (length + breadth);
    
    printf("Area = %d\nPerimeter = %d\n", area, peri);
    return 0;
}