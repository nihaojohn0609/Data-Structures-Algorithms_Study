#include <stdio.h>

int main() {
    int A[11] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int low = 6, num = 11;
	int diff = low - 0;
    int i;
    for(i = 0; i < num; i++) {
        if(A[i] - i != diff) {
            while(diff < A[i] - i) {
                printf("%d is missing in A.\n", i + diff);
                diff++;
            }
        }
    }
    
    int l = 1, h = 12;
    int n = 10;
    int B[10] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int H[10] = {0};
    for(i = 0; i < n; i++) {
        H[B[i]]++;
    }
    
    for(i = l; i < h; i++) {
        if(H[i] == 0) {
            printf("%d is missing in B.\n", i);
        }
    }
    
	return 0;
}
