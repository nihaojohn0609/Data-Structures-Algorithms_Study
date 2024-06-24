#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b) {
    r -> length = l;
    r -> breadth = b;
}

int area(struct Rectangle r) {
    return r.length * r.breadth;
}

int perimeter(Rectangle r) {
    int p;
    p = 2 * (r.length + r.breadth);
    
    return p;
}

int main() {
    Rectangle r = {0, 0};
    
    int l, b;
    printf("Enter Length and Breadth: \n");
    cin >> l >> b;
    
    initialize(&r, l, b);
    
    int a = area(r);
    int peri = perimeter(r);
    
    printf("Area = %d\nPerimeter = %d\n", a, peri);
    
    return 0;
}