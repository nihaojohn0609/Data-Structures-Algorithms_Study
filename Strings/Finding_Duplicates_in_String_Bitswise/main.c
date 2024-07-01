#include <stdio.h>

int main() {
	char A[] = "finding";
    long int H = 0, x = 0;
    int i;
    for(i = 0; A[i] != '\0'; i++) {
        x = 1;
        x  = x << (A[i] - 97);
        if((x & H) > 1) {
            printf("%c is duplicated.\n", A[i]);
        } else {
            H = x | H;
        }
    }
    
	return 0;
}
