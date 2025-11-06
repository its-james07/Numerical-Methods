#include<stdio.h>
#include<conio.h>
#include<math.h>

double f(double x){
    return (pow(x,2)-4*x-10);
}

int main(){
    double a,b,E, m;
    printf("Enter the initail interval(a,b): ");
    scanf("%lf%lf", &a, &b);
    printf("Enter error tolerance(E): ");
    scanf("%lf", &E);
    if(f(a)*f(b) > 0){
        printf("Error: No root in given interval");
        return -1;
    }
    while(fabs(f(m)) > E){
    m = (a+b)/2;
    if((f(m)*f(a) < 0)){
        b = m; }
    else{ 
        a = m; }
    }
    printf("Root = %f", m);
    getch();
    return 0;
}