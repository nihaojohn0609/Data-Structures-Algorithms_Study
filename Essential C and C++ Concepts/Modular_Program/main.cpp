#include <iostream>

using namespace std;

area(int length, int breadth) {
    return length * breadth;
}

int perimeter(int length, int breadth) {
    int p;
    p = 2 * (length + breadth);
    
    return p;
}

int main() {
    int length = 0, breadth = 0;

    printf("Enter Length and Breadth:\n");
    cin >> length >> breadth;
    
    int a = area(length, breadth);
    int peri = perimeter(length, breadth);
    
    printf("Area = %d\nPerimeter = %d\n", a, peri);
    return 0;
}