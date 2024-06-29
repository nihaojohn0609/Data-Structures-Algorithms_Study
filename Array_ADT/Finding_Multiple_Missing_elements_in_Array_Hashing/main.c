#include <stdio.h>

int main() {
	int l = 1, h = 12;
    int n = 10;
    int i;
    int A[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int H[10] = {0};
    for(i = 0; i < n; i++) {
        H[A[i]]++;
    }
    
    for(i = l; i < h; i++) {
        if(H[i] == 0) {
            printf("%d is missing in A.\n", i);
        }
    }
    
    return 0;
}
