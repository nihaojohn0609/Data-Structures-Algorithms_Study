#include <stdio.h>

int main() {
	char A[] = "WELCOME";
    int i;
    for(i = 0; A[i] != '\0'; i++) {
        A[i] = A[i] + 32;
    }
    printf("%s\n", A);
    
    char B[] = "wElCome";
    for(i = 0; B[i] != '\0'; i++) {
        if(B[i] >= 65 && B[i] <= 90) {
            B[i] += 32;
        } else if(B[i] >= 'a' && B[i] <= 122) {
            B[i] -= 32;
        }
    }
    printf("%s", B);
	return 0;
}
