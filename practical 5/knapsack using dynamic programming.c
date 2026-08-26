#include <stdio.h>

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

   
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {

                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum value = %d\n", dp[n][W]);

    return 0;
}