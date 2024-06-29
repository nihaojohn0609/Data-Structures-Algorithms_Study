#include <stdio.h>

double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    
    if(n == 0) {
        return 1;
    }
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

double sinx(double x, int n) {
    static double p, f = 1;
    double r;
    
    if(n == 0) {
        p = x;
        return x;
    }
    r = sinx(x, n - 1);
    p = p * (-x * x);
    f = f * (2 * n) * (2 * n + 1);
    return r + p / f;
}

double cosx(double x, int n) {
    static double p = 1, f = 1;
    double r;
    
    if(n == 0) {
        return 1;
    }
    r = cosx(x, n - 1);
    p = p * (-x * x);
    f = f * (2 * n - 1) * (2 * n);
    return r + p / f;
}

int main() {
    printf("%lf \n", e(1, 15));
//	printf("%lf \n", sinx(30, 100));
//	printf("%lf \n", cosx(30, 100));
	return 0;
}
