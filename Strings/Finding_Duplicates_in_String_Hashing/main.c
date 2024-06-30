#include <stdio.h>

int main() {
//	char A[] = "finding";
//    int H[26] = {0};
//    int i;
//    
//    for(i = 0; A[i] != '\0'; i++) {
//        H[A[i] - 97] += 1;
//    }
//    for(i = 0; i < 26; i++) {
//        if(H[i] > 1) {
//            printf("%c is duplicated for %d times.\n", i + 97, H[i]);
//        }
//    }
    
    char A[] = "fInding";
    int H[26] = {0};
    int i;
    
    for(i = 0; A[i] != '\0'; i++) {
        if(A[i] >= 65 && A[i] <= 90) {
            H[A[i] - 65] += 1;
        } else if(A[i] >= 97 && A[i] <= 122) {
            H[A[i] - 97] += 1;
        }
    }
    for(i = 0; i < 26; i++) {
        if(H[i] > 1) {
            printf("%c is duplicated for %d times.\n", i + 97, H[i]);
        }
    }
	return 0;
}