#include <bits/stdc++.h>

using namespace std;

long long N, W, w[120], v[120], dp[100005];

int main() {

    cin >> N >> W;

    for (int i=0; i<N; i++) {
        cin >> w[i] >> v[i];
    }

    memset(dp, 0, sizeof dp);

    for (int i=0; i<N; i++) {
        for (int j=W; j>=w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[W] << endl;


    return 0;
}