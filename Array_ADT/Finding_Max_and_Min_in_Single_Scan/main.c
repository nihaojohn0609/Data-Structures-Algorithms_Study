#include <stdio.h>

int main(int argc, char **argv) {
	int A[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int min = A[0];
    int max = A[0];
    int n = 10;
    int i;
    
    for(i = 0; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
        } else if(A[i] > max) {
            max = A[i];
        }
    }
    printf("max is %d, min is %d.", max, min);
	return 0;
}
