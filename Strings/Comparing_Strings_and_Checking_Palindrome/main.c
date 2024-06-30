#include <stdio.h>

int main() {
//    char A[] = "Painter";
//    char B[] = "Painting";
//    int i, j;
//    
//    for(i = 0, j = 0; A[i] != '\0' && B[i] != '\0'; i++, j++) {
//        if(A[i] != B[j]) {
//            break;
//        }
//    }
//    if(A[i] == B[j]) {
//        printf("Equal\n");
//    } else if(A[i] < B[j]) {
//        printf("Smaller\n");
//    } else {
//        printf("Greater\n");
//    }
    
    int i, j;
    char temp;
    int length;
    char C[] = "madam";
//    char D[6];
    
    for(i = 0; C[i] != '\0'; i++) {
        
    }
    length = i; // Only used for second method
    i = i - 1;
//    for(j = 0; i >= 0; j++, i--) {
//        D[j] = C[i];
//    }
//    D[j] = '\0';

    for(j = 0; j < i; j++, i--) {
        temp = C[j];
        C[j] = C[i];
        C[i] = temp;
    }
    
//    for(i = 0, j = 0; C[i] != '\0' && D[i] != '\0'; i++, j++) {
//        if(C[i] != D[j]) {
//            break;
//        }
//    }
//    if(C[i] == D[j]) {
//        printf("This is a Palindrome.");
//    } else {
//        printf("This is not a Palindrome.");
//    }

    for(i = 0, j = length - 1; i < j; i++, j--) {
        if(C[i] != C[j]) {
            break;
        }
    }
    if(C[i] == C[j]) {
        printf("This is a Palindrome.");
    } else {
        printf("This is not a Palindrome.");
    }
	return 0;
}
