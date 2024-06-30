#include <stdio.h>

int main() {
    int A[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int H[9] = {0};
    int n = 10;
    int i;
    for(i = 0; i < n; i++) {
        H[A[i]]++;
    }
	
    for(i = 0; i <= 8; i++) {
        if(H[i] > 1) {
            printf("%d is duplicated for %d times.\n", i, H[i]);
        }
    }
	return 0;
}
