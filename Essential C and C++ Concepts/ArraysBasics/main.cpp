#include <iostream>

using namespace std;

int main() {
    
    int A[5];
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;
    
    int B[10] = {2, 4, 6, 8, 10, 12, 14};
    
    cout << sizeof(A) << endl;
    cout << A[1] << endl;
    printf("%d\n", A[2]);
    cout << sizeof(B) << endl;
    cout << B[8] << endl;
    printf("%d\n", B[9]);
    
    for(int i = 0; i < 10; i++) {
        cout << B[i] << endl;
    }
    
    for(int x:B) {
        cout << x << endl;
    }
    
    int n;
    cout << "Enter size";
    cin >> n;
    int C[n];
    C[0] = 2;
    
    for(int x:C) {
        cout << x << endl;
    }
    return 0;
}