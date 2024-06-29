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
    
	return 0;
}
