#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*sin(x) + cos(x);
}

int main() {
    double a, b, m, E;

    printf("Enter the initial interval (a b): ");
    scanf("%lf %lf", &a, &b);

    printf("Enter error tolerance E: ");
    scanf("%lf", &E);

    if (f(a) * f(b) > 0) {
        printf("Error: No root in the given interval\n");
        return -1;
    }

    while(fabs(f(m)) > E){
        m = (a*f(b) - b*f(a)) / (f(b) - f(a));

        if (f(a) * f(m) < 0)
            b = m;
        else
            a = m;
    }
    printf("Root = %.6lf\n", m);
    return 0;
}
