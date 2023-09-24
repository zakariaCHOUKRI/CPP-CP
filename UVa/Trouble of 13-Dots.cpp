// UVa 10819 - Trouble of 13-Dots

#include <bits/stdc++.h>

using namespace std;

int knapsack(int W, int n, int prices[], int weights[], int memo[][1001]) {

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

int main(){

    int n, m;
    int prices[101], weights[101], memo[1001][1001];

    while (scanf("%d %d", &m, &n) != EOF) {

        for (int i=0; i<n; i++) scanf("%d %d", &weights[i], &prices[i]);

        for (int j=0; j<1001; j++) {
            for (int k=0; k<1001; k++) {
                memo[j][k] = -1;
            }
        }

        printf("%d\n", knapsack(m, n, prices, weights, memo));

    }

    return 0;
}