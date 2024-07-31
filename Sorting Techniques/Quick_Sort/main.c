#include <stdio.h>
#include <stdint.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n) {
    int i, j, flag;
    for(i = 0; i < n - 1; i++) {
        flag = 0;
        for(j = 0; j < n - i - 1; j++) {
            if(A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        } 
        if(flag == 0) {
            break;
        }
    }
}

void InsertionSort(int A[], int n) {
    int i, j, x;
    
    for(i = 1; i < n; i++) {
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void SelectionSort(int A[], int n) {
    int i, j, k;
    
    for(i = 0; i < n - 1; i++) {
        for(j = k = i; j < n; j++) {
            if(A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    
    do {
        do {
            i++;
        } while(A[i] <= pivot);
        do {
            j--;
        } while(A[j] > pivot);
        if(i < j) {
            swap(&A[i], &A[j]);
        }
    } while(i < j);
    
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h) {
    int j;
    
    if(l < h) {
        j = partition(A, l, h);
        QuickSort(A, l, j); // j position element, which is already sorted, acts as infinity for first list
        QuickSort(A, j+1, h); // h is having infinity for right side list
    }
}

int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, INT32_MAX};
    int n = 11;
    int i;
    
    QuickSort(A, 0, n - 1);
    
    for(i = 0; i < n - 1; i++) {
        printf("%d ", A[i]);
    }
	printf("\n");
	return 0;
}