#include <iostream>

using namespace std;

class UpperTri {
private:
    int *A;
    int n;
public:
    UpperTri() {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    UpperTri(int n) {
        this -> n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~UpperTri() {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {
        return n;
    }
};

void UpperTri::Set(int i, int j, int x) {
    if(i <= j) {
        A[n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)] = x;
    }
}

int UpperTri::Get(int i, int j) {
    if(i <= j) {
        return A[n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)];
    } else {
        return 0;
    }
}

void UpperTri::Display() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i <= j) {
               cout << A[n * (i - 1) - (i - 2) * (i - 1) / 2 + (j - i)] << " "; 
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    
    UpperTri lm(d);
    
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