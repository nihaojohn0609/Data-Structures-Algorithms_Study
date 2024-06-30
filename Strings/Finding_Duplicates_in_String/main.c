#include <stdio.h>

int main() {
	char A[] = "finding";
    int i, j;
    int count;
    for(i = 0; A[i] != 0; i++) {
        count = 1;
        if(A[i] != -1) {
            for(j = i + 1; A[j] != 0; j++) {
                if(A[i] == A[j]) {
                    count++;
                    A[j] = -1;
                }
            }
            if(count > 1) {
                printf("%c is duplicated for %d times.\n", A[i], count); 
            }
        }
    }
	return 0;
}
