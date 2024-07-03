#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int *A;
    int n;
};

void Create(struct Matrix *m, int n) {
    int i, j;
    printf("Enter all the elements: ");
    for(i = 1; i <= m -> n; i++) {
        for(j = 1; j <= i; j++) {
            scanf("%d", &m -> A[i*(i - 1) / 2 + j - 1]);
        }
    }
} 

void Set(struct Matrix *m, int i, int j, int x) {
    if(i >= j) {
        m -> A[i*(i - 1) / 2 + j - 1] = x;
    }
}

int Get(struct Matrix m, int i, int j) {
    if(i >= j) {
        return m.A[i*(i - 1) / 2 + j - 1];
    } else {
        return 0;
    }
}

void Display(struct Matrix m) {
    int i, j;
    for(i = 1; i <= m.n; i++) {
        for(j = 1; j <= m.n; j++) {
            if(i >= j) {
                printf("%d ", m.A[i*(i - 1) / 2 + j - 1]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int ch, x, i, j;
    struct Matrix m;
    printf("Enter dimension: ");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
//    A = new int[n];
    do {
        // Display Menu
        printf("Menu\n");
        printf("1. Create\n");
        printf("2. Get\n");
        printf("3. Set\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");
        
        switch(ch) {
            case 1: 
                Create(&m, m.n);
                break;
            case 2:
                printf("Enter indices: ");
                scanf("%d %d", &i, &j);
                x = Get(m, i, j);
                printf("The element is %d\n", x);
                break;
            case 3:
                printf("Enter row, column, and element: ");
                scanf("%d %d %d", &i, &j, &x);
                Set(&m, i, j, x);
            case 4: 
                Display(m);
        }
    } while (ch < 5);
        return 0;   
}
