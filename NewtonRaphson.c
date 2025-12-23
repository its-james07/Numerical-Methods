#include<stdio.h>
#include<conio.h>
#include<math.h>
double f(double x){
    return x*sin(x)+cos(x); }
double g(double x){
    return x*cos(x); }
int main(){
   double x0, x1, E;
   int  I= 0, N;
   printf("Your initial guess: ");
   scanf("%lf", &x0);
   printf("Error Tolerance(E) ");
   scanf("%lf", &E);
   printf("Maximum Iterations(N) ");
   scanf("%d", &N);
   while(fabs(f(x0)) > E){
    if(fabs(g(x0)) < 0.0005){
        printf("Error! First Derivative Approximately Zero");
        return -1;
    }
    x1 = x0 - f(x0)/g(x0);
    x0 = x1;
    I = I + 1;
    if(I > N){
        printf("Error: Not Convergent!");
        return -1;
    }
   }
   printf("After %d Iterations, Root = %f", I, x0);
   return 0;
}