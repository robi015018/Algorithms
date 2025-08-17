#include <stdio.h>

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int rodCutting(int price[], int n) 
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) 
    {
        int max_val = -1;
        for (int j = 0; j < i; j++) 
        {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}
int main() 
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int rodLength = 8;

    int maxProfit = rodCutting(price, rodLength);
    printf("Maximum Obtainable Value = %d\n", maxProfit);

    return 0;
}