#include <stdio.h>

int main() {
    int n = 10;
    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
	int lastDuplicate = 0;
    int i, j;
    for(i = 0; i < n; i++) {
        if(A[i] == A[i + 1] && A[i] != lastDuplicate) {
            printf("%d is dulpicated.\n", A[i]);
            lastDuplicate = A[i];
        }
    }
    
    for(i = 0; i < n - 1; i++) {
        if(A[i] == A[i + 1]) {
            j = i + 1;
            while(A[j] == A[i]) {
                j++;
            }
            printf("%d is duplicated for %d times.\n", A[i], j - i);
            i = j - 1;
        }
    }
	return 0;
}
