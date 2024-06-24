#include <iostream>

using namespace std;

// Call by Value
//int add(int a, int b) {
//    int c;
//    c = a + b;
//    
//    return c;
//}
//
//int main() {
//    int num1 = 10, num2 = 15, sum;
//    
//    sum = add(num1, num2);
//    
//    cout << "Sum is " << sum;
//    
//    return 0;
//}

// Call by Address
//void swap(int *x, int *y) {
//    int temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//int main() {
//    int num1 = 10, num2 = 15;
//    
//    swap(&num1, &num2);
//    
//    cout << "First Number " << num1 << endl;
//    cout << "Second Number " << num2 << endl;
//    
//    return 0;
//}

// Call by Reference
void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int num1 = 10, num2 = 15;
    
    swap(num1, num2);
    
    cout << "First number " << num1 << endl;
    cout << "Second number " << num2 << endl;
    
    return 0;
}