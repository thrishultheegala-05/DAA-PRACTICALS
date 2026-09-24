#include <stdio.h>
#include <limits.h>

int main()
{
    int n, amount;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter the coin denominations: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        printf("Change cannot be made for the given amount.");
    }
    else
    {
        printf("Minimum number of coins required: %d", dp[amount]);
    }

    return 0;
}