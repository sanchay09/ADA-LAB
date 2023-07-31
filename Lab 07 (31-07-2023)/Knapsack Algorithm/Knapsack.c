#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n, int selected[])
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else {
            selected[i - 1] = 1;
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }

    return K[n][W];
}

int main() {
    int n, W, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n], selected[n];
    printf("Enter the values of the items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter the weights of the items: ");
    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int max_profit = knapSack(W, wt, val, n, selected);
    printf("The maximum profit is %d\n", max_profit);

    printf("The objects selected for the optimal solution are: ");
    for (i = 0; i < n; i++) {
        if (selected[i]==1)
            printf("%d ", i + 1);
    }
    return 0;
}
