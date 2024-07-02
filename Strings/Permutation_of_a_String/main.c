#include <stdio.h>

void perm(char S[], int k) {
     static int A[10] = {0};
     static char Res[10];
     int i;
     if(S[k] == '\0') {
         Res[k] = '\0';
         printf("%s\n", Res);
     } else {
         for(i = 0; S[i] != '\0'; i++) {
             if(A[i] == 0) {
                 Res[k] = S[i];
                 A[i] = 1;
                 perm(S, k + 1);
                 A[i] = 0;
             }
         }
     }
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void perm2(char S[], int low, int high) {
    int i;
    if(low == high) {
        printf("%s\n", S);
    } else {
        for(i = low; i < high; i++) {
            swap(&S[low], &S[i]);
            perm2(S, low + 1, high);
            swap(&S[low], &S[i]);
        }
    }
} 

int main() {
	char S[] = "ABC";
//    perm(S, 0);
    perm2(S, 0, 3);
	return 0;
}


