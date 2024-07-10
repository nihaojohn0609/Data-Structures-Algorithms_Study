#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *A;
    int n;
    int lower_diag;
    int upper_diag;
};

void Set(struct Matrix *m, int i, int j, int x) {
    if(i - j >= -m -> upper_diag && i - j <= m -> lower_diag) {
        int index = m -> lower_diag * m -> n + j - i + (i - j) * m -> n;
        m -> A[index] = x;
    }
}

int Get(struct Matrix m, int i, int j) {
    if(i - j >= -m.upper_diag && i - j <= m.lower_diag) {
        int index = m.lower_diag * m.n + j - i + (i - j) * m.n;
        return m.A[index];
    }
    return 0;
}

void Display(struct Matrix m) {
    int i, j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            if(i - j >= -m.upper_diag && i - j <= m.lower_diag) {
                int index = m.lower_diag * m.n + j - i + (i - j) * m.n;
                printf("%d ", m.A[index]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Matrix m;
    int i, j, x;
    printf("Enter dimension: ");
    scanf("%d", &m.n);
    
    printf("Enter number of lower diagonals: ");
    scanf("%d", &m.lower_diag);
    
    printf("Enter number of upper diagonals: ");
    scanf("%d", &m.upper_diag);
    
    int size = (m.lower_diag + m.upper_diag + 1) * m.n;
    m.A = (int *)malloc(size * sizeof(int));
    
    printf("Enter all elements: ");
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n");
    Display(m);
	return 0;
}