#include <stdio.h>

int main() {
	char A[] = "decimal";
    char B[] = "medical";
    int i, j, count;;
    for(i = 0; A[i] != '\0'; i++) {
        count = 0;
        for(j = 0; B[j] != '\0'; j++) {
            if(A[i] == B[j]) {
                B[j] = '0';
                count++;
                break;
            }
        }
        if(B[j] == '\0') {
            break;
        }
    }
    if(count == 1) {
        printf("It is an anagram.");
    } else {
        printf("It is not an anagram.");
    }
	return 0;
}
