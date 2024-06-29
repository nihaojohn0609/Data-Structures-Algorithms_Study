#include <stdio.h>

int main() {
    int n = 10;
    int s;
    int i;
    int A[10] = {1, 2, 3, 4, 5, 6, 8, 9, 10};
    int B[11] = {6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17};
    
    int sum = 0;
    for(i = 0; i < n; i++) {
        sum += A[i];
    }
    s = n * (n + 1) / 2;
    printf("missing number is %d\n", s - sum);
    
    int low = 6, count = 11;
    int diff = low - 0;
    for(int i = 0; i < count; i++) {
        if(B[i] - i != diff) {
            printf("missing element is %d\n", i + diff);
            break;
        }
    }
    
	return 0;
}
