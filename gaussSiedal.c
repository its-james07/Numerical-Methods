#include <stdio.h>
#include <math.h>
#define M 10     
int main() {
    int n, i, j, k;
    int MaximumItrn = 500;
    double E = 0.000005;  
    double A[M][M+1];     
    double X[M];          
    double Z[M];          
    double D[M];          
    printf("Enter the number of unknowns: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for number of unknowns.\n");
        return 1;
    }
    if (n <= 0 || n > M) {
        printf("Error: number of unknowns must be between 1 and %d.\n", M);
        return 1;
    }

    printf("\nEnter the augmented matrix (row-wise):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n+1; j++)
            if (scanf("%lf", &A[i][j]) != 1) {
                printf("Invalid input for matrix element.\n");
                return 1;
            }

    printf("\nEnter initial guess for the solution:\n");
    for(i = 0; i < n; i++)
        if (scanf("%lf", &X[i]) != 1) {
            printf("Invalid input for initial guess; using 0 for remaining.\n");
            for (; i < n; i++) X[i] = 0.0;
            break;
        }

    k = 0;
    double Dmax;
    do {
        k++;
        if(k > MaximumItrn) {
            printf("Error: No convergence after %d iterations!\n", MaximumItrn);
            return 0;
        }

        for(i = 0; i < n; i++) {
            if (fabs(A[i][i]) < 1e-15) {
                printf("Error: Zero (or near-zero) diagonal element at row %d. Cannot divide.\n", i+1);
                return 1;
            }
            Z[i] = X[i];           
            X[i] = A[i][n];        
            for(j = 0; j < n; j++) {
                if(j != i) {
                    X[i] -= A[i][j] * X[j];
                }
            }
            X[i] /= A[i][i];       
            D[i] = fabs(X[i] - Z[i]); 
        }

        Dmax = D[0];
        for(i = 1; i < n; i++) {
            if(D[i] > Dmax)
                Dmax = D[i];
        }

    } while(Dmax > E);  
    printf("\nSolution after %d iterations:\n", k);
    for(i = 0; i < n; i++)
        printf("x%d = %.6lf\n", i+1, X[i]);
    return 0;
}
