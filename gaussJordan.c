#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10
void main(){
    int n, i, j, k;
    double A[MAX][MAX+1], X[MAX];
    double ratio;
    printf("How many unknowns? ");
    scanf("%d", &n);
    printf("\nEnter the augmented co-eff matrix: \n");
    for(i = 0; i<n; i++){
        for(j = 0; j<n+1; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    for(j = 0; j<n; j++){
        if(fabs(A[j][j]) < 0.00005){
            printf("\nError: Pivot element approx. zero!");
            getch();
            return;
        }
        for(i = 0; i<n; i++){
            if(i != j){
                ratio = A[i][j] / A[j][j];
                for(k = j; k<=n; k++){
                    A[i][k] = A[i][k] - ratio * A[j][k];
                }
            }
        }
    }
    for(i = 0; i<n; i++)
        X[i] = A[i][n] / A[i][i];
        printf("\nSolution:\n");
        for(i = 0; i<n; i++){
            printf("X[%d] = %.4f\n",i+1, X[i]);
            
        }
        getch();
}