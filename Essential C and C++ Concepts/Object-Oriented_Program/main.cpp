#include <iostream>

using namespace std;

class Rectangle {
public:
    int length;
    int breadth;


    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    int perimeter() {
        int p;
        p = 2 * (length + breadth);
        
        return p;
    }
};

int main() {
    Rectangle r;
    
    int l, b;
    printf("Enter Length and Breadth: \n");
    cin >> l >> b;
    
    r.initialize(l, b);
    
    int a = r.area();
    int peri = r.perimeter();
    
    printf("Area = %d\nPerimeter = %d\n", a, peri);
    
    return 0;
}