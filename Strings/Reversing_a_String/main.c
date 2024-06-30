#include <stdio.h>

int main() {
	char A[] = "python";
//    char B[7];
    int i, j;
    char temp;
//    for(i = 0; A[i] != '\0'; i++) {
//        
//    }
//    i = i - 1;
//    for(j = 0; i >= 0; j++, i--) {
//        B[j] = A[i];
//    }
//    B[j] = '\0';
//    printf("%s", B);

    for(j = 0; A[j] != '\0'; j++) {
        
    }
    j = j - 1;
    for(i = 0; i < j; i++, j--) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("%s", A);
	return 0;
}
