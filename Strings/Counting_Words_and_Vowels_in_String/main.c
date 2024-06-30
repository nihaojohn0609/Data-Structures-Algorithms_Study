#include <stdio.h>

int main() {
	char A[] = "How are you";
    int i, vcount = 0, ccount = 0, word = 1;
    for(i = 0; A[i] != '\0'; i++) {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U') {
            vcount++;
        } else if((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122)) {
            ccount++;
        }
    }
    
    for(i = 0; A[i] != '\0'; i++) {
        if(A[i] == ' ' && A[i - 1] != ' ') {
            word++;
        }
    }
    
    printf("Number of vowels is %d, number of consonants is %d, and the number of words is %d.", vcount, ccount, word);
	return 0;
}
