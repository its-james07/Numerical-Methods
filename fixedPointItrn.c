    #include<stdio.h>
    #include<conio.h>
    #include<math.h>
    /*for f(x) = cos(x) + 3(x) - 2*/
    double g(double x) { 
        return (2-cos(x))/3;
    }
    void main(){
        double x0, x1, E, err;
        int I, N; 
        printf("Initial guesses (x0): ");
        scanf("%lf", &x0);
        printf("Error Tolerance(E): ");
        scanf("%lf", &E);
        printf("Maximum Iteration (N) : ");
        scanf("%d", &N);
        I = 0;  
        do {
            x1 = g(x0);
            err = fabs(x1 - x0);
            x0 = x1; 
            I = I + 1; 
            if(I > N){
                printf("Error: Not Convergent!");
                return;
            }
        }while(err > E);
        printf("After %d iterations, Root = %f", I, x0);
        getch();
    }