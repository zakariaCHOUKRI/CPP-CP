// UVa 10130 - SuperSale

#include <bits/stdc++.h>

using namespace std;

int knapsack(int W, int n, int prices[], int weights[], int memo[][101]) {

    if (memo[n][W] != -1) return memo[n][W];

    if (n == 0 || W == 0) {
        memo[n][W] = 0;
        return 0;
    }

    if (weights[n-1] > W) {
        memo[n][W] = knapsack(W, n-1, prices, weights, memo);
        return memo[n][W];
    }

    else {
        memo[n][W] = max(knapsack(W, n-1, prices, weights, memo),
                         prices[n-1] + knapsack(W-weights[n-1], n-1, prices, weights, memo));
        return memo[n][W];
    }


}

int main() {

    int t, n, g, sum;
    int prices[1001], weights[1001], maximalWeights[101], memo[1001][101];

    scanf("%d", &t);
    while(t--) {

        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d %d", &prices[i], &weights[i]);

        scanf("%d", &g);
        for (int i=0; i<g; i++) scanf("%d", &maximalWeights[i]);

        sum = 0;
        for (int i=0; i<g; i++) {
            
            for (int j=0; j<1001; j++) {
                for (int k=0; k<101; k++) {
                    memo[j][k] = -1;
                }
            }

            sum += knapsack(maximalWeights[i], n, prices, weights, memo);

        }

        printf("%d\n", sum);
    }



    return 0;
}