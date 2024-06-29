#include <stdio.h>

double e(int x, int n) {
    static double s;
    if(n == 0) {
        return s;
    }
    s = 1 + x * s / n;
    return e(x, n - 1);
}

double sinx(double x, int n) {
    static double s;
    if(n == 0) {
        return s;
    }
    s = x + (-x * x) * s / ((2 * n) * (2 * n + 1));
    return sinx(x, n - 1);
}

double cosx(double x, int n) {
    static double s;
    if(n == 0) {
        return s;
    }
    s = 1 + (-x * x) * s / ((2 * n - 1) * (2 * n));
    return cosx(x, n - 1);
}

int main() {
	printf("%lf \n", e(1, 15));
	return 0;
}