#include <stdio.h>

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

int main() {
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n = 10;
    int i;
    
    InsertionSort(A, n);
    
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
	printf("\n");
	return 0;
}