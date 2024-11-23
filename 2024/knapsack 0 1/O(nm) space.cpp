#include <bits/stdc++.h>

using namespace std;

long long N, W, w[120], v[120], dp[120][100005];

int main() {

    cin >> N >> W;

    for (long long i=0; i<N; i++) {
        cin >> w[i] >> v[i];
    }

    for (long long j=0; j<=W; j++) {
        if (w[0] > j) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = v[0];
        }
    }

    for (long long i=1; i<N; i++) {
        for (long long j=0; j<=W; j++) {
            if (w[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N-1][W] << endl;


    return 0;
}