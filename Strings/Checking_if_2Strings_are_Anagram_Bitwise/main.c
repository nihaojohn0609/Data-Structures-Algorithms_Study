#include <stdio.h>

int main() {
	char A[] = "decimal";
    char B[] = "medical";
    int i;
    int g, h;
    
    for(i = 0; A[i] != '\0'; i++) {
        g = 1;
        g = g << (A[i] - 97);
        h = h | g;
    }
    for(i = 0; B[i] != '\0'; i++) {
        g = 1;
        g = g << (B[i] - 97);
        if((h & g) == 0) {
            printf("It is not an anagram.");
            return 0;
        } 
    }
    printf("It is an anagram.");
	return 0;
}
