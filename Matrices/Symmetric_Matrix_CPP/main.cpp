#include <iostream>

using namespace std;

class Symmetric {
private:
    int *A;
    int n;
public:
    Symmetric() {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    Symmetric(int n) {
        this -> n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~Symmetric() {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {
        return n;
    }
};

void Symmetric::Set(int i, int j, int x) {
    if(i >= j) {
        A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}

int Symmetric::Get(int i, int j) {
    if(i >= j) {
        return A[i * (i - 1) / 2 + (j - 1)];
    } else {
        return A[j * (j - 1) / 2 + (i - 1)];
    }
}

void Symmetric::Display() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= j) {
               cout << A[i * (i - 1) / 2 + (j - 1)] << " "; 
            } else {
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    
    Symmetric lm(d);
    
    int x;
    cout << "Enter All Elements: ";
    for(int i = 1; i <= d; i++) {
        for(int j = 1; j <= d; j++) {
            cin >> x;
            lm.Set(i , j, x);
        }
    }
    cout << endl;
    lm.Display();
    
    return 0;
}