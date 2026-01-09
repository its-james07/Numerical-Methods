#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 10
int main() {
int n, i, j, k;
double A[MAX][MAX], B[MAX][MAX];
double ratio, diag;

printf("Enter the size of square matrix: ");
scanf("%d", &n);

if (n <= 0 || n > MAX) {
    printf("Invalid matrix size!");
    return 1;
}

printf("\nEnter the matrix elements:\n");
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        scanf("%lf", &A[i][j]);
        B[i][j] = (i == j) ? 1.0 : 0.0;   // Identity matrix
    }
}

for (j = 0; j < n; j++) {
    if (fabs(A[j][j]) < 0.00005) {
        printf("\nError: Pivot element is approximately zero!");
        return 1;
}
diag = A[j][j];
    for (k = 0; k < n; k++) {
        A[j][k] /= diag;
        B[j][k] /= diag;
}
for (i = 0; i < n; i++) {
    if (i != j) {
        ratio = A[i][j];
        for (k = 0; k < n; k++) {
            A[i][k] -= ratio * A[j][k];
            B[i][k] -= ratio * B[j][k];
            }
        }
    }
}
printf("\nInverse Matrix:\n");
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        printf("%10.4f", B[i][j]);
    }
    printf("\n");
}
getch();
return 0;
}
