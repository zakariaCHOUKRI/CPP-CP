#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, W, w[105], v[105], dp[105][100005];

ll knapsack(ll remaining_items, ll remaining_weight) {

    if (remaining_items == 0 || remaining_weight == 0) {
        return 0;
    }

    if (dp[remaining_items][remaining_weight] != -1) {
        return dp[remaining_items][remaining_weight];
    }

    if (remaining_weight < w[N-remaining_items]) {
        dp[remaining_items][remaining_weight] = knapsack(remaining_items-1, remaining_weight);
        return dp[remaining_items][remaining_weight];
    }

    else {
        dp[remaining_items][remaining_weight] = max(knapsack(remaining_items-1, remaining_weight), knapsack(remaining_items-1, remaining_weight-w[N-remaining_items]) + v[N-remaining_items]);
        return dp[remaining_items][remaining_weight];
    }
}

int main() {

    cin >> N >> W;

    for (int i=0; i<N; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp, -1, sizeof dp);

    cout << knapsack(N, W) << endl;

    return 0;
}