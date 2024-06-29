#include <stdio.h>

double e(int x, int n) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    
    for(i = 1; i <= n; i++) {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

double sinx(double x, int n) {
    double s = x;
    int i;
    double num = x;
    double den = 1;
    
    for(i = 1; i <= n; i++) {
        num *= (-x * x);
        den *= (2 * i) * (2 * i + 1);
        s += num / den;
    }
    return s;
}

double cosx(double x, int n) {
    double s = 1;
    int i;
    double num = 1;
    double den = 1;
    
    for(i = 1; i <= n; i++) {
        num *= (-x * x);
        den *= (2 * i - 1) * (2 * i);
        s += num / den;
    }
    return s;
}

int main() {
	printf("%lf \n", cosx(15, 100));
	return 0;
}
