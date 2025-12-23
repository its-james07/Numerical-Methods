#include<stdio.h>
#include<math.h>
double f(double x) {
    return (4*pow(x,3)-2*x-6);
}
int main() {
    double a, b, c, E; 
    int I, N; 
    
    printf("Initial guesses (a,b): ");
    scanf("%lf%lf", &a, &b);
    printf("Error tolerance (E): ");
    scanf("%lf", &E); 
    printf("Maximum number of iterations: ");
    scanf("%d", &N); 
    I = 0;
    do {
        if(fabs(f(b) - f(a)) < 0.000005) { 
            printf("Mathematical Error!");
            return 0; 
        }
        
        c = (a*f(b) - b*f(a)) / (f(b) - f(a)); 
        a = b; 
        b = c; 
        I = I + 1; 
        
        if(I > N) { 
            printf("Error: Not Convergent! ");
            return 0; 
        }
    } while(fabs(f(c)) > E);
    
    printf("After %d iterations, Root = %f", I, c);
    return 0; 
}
