#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter the dimensions of matrices:\n");
    printf("For %d matrices, enter %d dimensions:\n", n, n + 1);

    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

   
    int m[n + 1][n + 1];

 
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %d\n", m[1][n]);

    return 0;
}