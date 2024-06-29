#include <iostream>

using namespace std;

template<class T>

class Array {
private:
    T *A;
    int size;
    int length;
    void swap(T *x, T *y);
public:
    Array() {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz) {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array() {
        delete []A;
    }
    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(T key);
    int BinarySearch(T key);
    T Get(int index);
    void Set(int index, int x);
    T Max();
    T Min();
    T Sum();
    T Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(T x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
    
};

template<class T>
void Array<T>::Display() {
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    } 
    cout << endl;
}

template<class T>
void Array<T>::Append(T x) {
    if(length < size) {
        A[length++] = x;
    }
}

template<class T>
void Array<T>::Insert(int index, T x) {
    if(index >= 0 && index <= length) {
        for(int i = length - 1; i >= index; i--) {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index) {
    T x = 0;
    if(index >= 0 && index < length) {
        x = A[index];
        for(int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

template<class T>
void Array<T>::swap(T *x, T *y) {
    T temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

template<class T>
int Array<T>::LinearSearch(T key) {
    int i;
    for(i = 0; i < length; i++) {
        if(key == A[i]) {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

template<class T>
int Array<T>::BinarySearch(int key) {
    int low, mid, high;
    low = 0;
    high = length - 1;
    
    while(low <= high) {
        mid = (low + high) / 2;
        if(key == A[mid]) {
            return mid;
        } else if(key < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

template<class T>
T Array<T>::Get(int index) {
    if(index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

template<class T>
void Array<T>::Set(int index, T x) {
    if(index >= 0 && index < length) {
        A[index] = x;
    }
}

template<class T>
T Array<T>::Max() {
    T max = A[0];
    int i;
    for(i = 1; i < length; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

template<class T>
T Array<T>::Min() {
    T min = A[0];
    int i;
    for(i = 1; i < length; i++) {
        if(A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

template<class T>
T Array<T>::Sum() {
    T total = 0;
    int i;
    for(i = 0; i < length; i++) {
        total += A[i];
    }
    return total;
}

template<class T>
T Array<T>::Avg() {
    return (T)Sum() / length;
}

template<class T>
void Array<T>::Reverse() {
    T *B;
    int i, j;
    
    B = new T[size];
    for(i = length - 1, j = 0; i >=0; i--, j++) {
        B[j] = A[i];
    }
    for(i = 0; i < length; i++) {
        A[i] = B[i];
    }
}

template<class T>
void Array<T>::Reverse2() {
    int i, j;
    for(i = 0, j = length - 1; i < j; i++, j--) {
        swap(&A[i], &A[j]);
    }
}

template<class T>
void Array<T>::InsertSort(T x) {
    int i = length - 1;
    if(length == size) {  // there is no free space
        return;
    }
    while(i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

template<class T>
int Array<T>::isSorted() {
    int i;
    for(i = 0; i < length - 1; i++) {
        if(A[i] > A[i + 1]) {
            return 0;
        } 
    }
    return 1;
}

template<class T>
void Array<T>::Rearrange() {
    int i, j;
    i = 0;
    j = length - 1;
    while(i < j) {
        while(A[i] < 0) {
            i++;
        }
        while(A[j] >= 0) {
            j--;
        }
        if(i < j) {
            swap(&A[i], &A[j]);
        }
    }
}

template<class T>
Array<T>* Array<T>::Merge(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array<T> *arr3 = new Array<T>(length + arr2.length);
    
    while(i < length && j < arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3 -> A[k++] = A[i++];
        } else {
            arr3 -> A[k++] = arr2.A[j++];
        }
    }
    for(; i < length; i++) {
        arr3 -> A[k++] = A[i];
    }
    for(; j < arr2.length; j++) {
        arr3 -> A[k++] = arr2.A[j];
    }
    arr3 -> length = length + arr2.length;
    
    return arr3; // could be returned as the array is created in heap
}

template<class T>
Array<T>* Array<T>::Union(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array<T> *arr3 = new Array<T>(length + arr2.length);
    
    while(i < length && j < arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3 -> A[k++] = A[i++];
        } else if(arr2.A[j] < A[i]) {
            arr3 -> A[k++] = arr2.A[j++];
        } else {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }
    for(; i < length; i++) {
        arr3 -> A[k++] = A[i];
    }
    for(; j < arr2.length; j++) {
        arr3 -> A[k++] = arr2.A[j];
    }
    arr3 -> length = length + arr2.length;
    
    return arr3; // could be returned as the array is created in heap
}

template<class T>
Array<T>* Array<T>::Intersection(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array<T> *arr3 = new Array<T>(length + arr2.length);
    
    while(length && j < arr2.length) {
        if(A[i] < arr2.A[j]) {
            i++;
        } else if(arr2.A[j] < A[i]) {
            j++;
        } else {
            arr3 -> A[k++] = A[i++];
            j++;
        }
    }
    arr3 -> length = length + arr2.length;
    
    return arr3; // could be returned as the array is created in heap
}

template<class T>
Array<T>* Array<T>::Difference(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array<T> *arr3 = new Array<T>(length + arr2.length);
    
    while(i < length && j < arr2.length) {
        if(A[i] < arr2.A[j]) {
            arr3 -> A[k++] = A[i++];
        } else if(arr2.A[j] < A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for(; i < length; i++) {
        arr3 -> A[k++] = A[i];
    }
    arr3 -> length = length + arr2.length;
    
    return arr3; // could be returned as the array is created in heap
}

int main() {
    Array<char> arr(10);
    
    arr.Insert(0, 'a');
    arr.Insert(1, 'c');
    arr.Insert(2, 'd');
    arr.Display();
    cout << arr.Delete(0) << endl;
    arr.Display();
    
    return 0;
}
