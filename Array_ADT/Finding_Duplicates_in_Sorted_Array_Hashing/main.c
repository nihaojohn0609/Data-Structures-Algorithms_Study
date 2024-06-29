#include <stdio.h>

int main() {
    int n = 10;
    int i;
    int A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int H[21] = {0};
	
    for(i = 0; i < n; i++) {
        H[A[i]]++;
    }
    for(i = 0; i <= 20; i++) {
        if(H[i] > 1) {
            printf("%d id duplicated %d times.\n", i, H[i]);
        }
    }
	return 0;
}
