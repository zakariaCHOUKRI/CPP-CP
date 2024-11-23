#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int l, A[55], n, dp[55][55];

int cut(int left, int right) {

    if (right - left <= 1) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    int res = INT_MAX;
    for (int i=left+1; i<right; i++) {
        res = min(res, cut(left, i) + cut(i, right) + A[right] - A[left]);
    }

    dp[left][right] = res;
    return res;

}

int main() {

    while (true) {
        cin >> l;
        if (l == 0) {
            break;
        }

        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> A[i];
        }
        A[0] = 0;
        A[n+1] = l;

        memset(dp, -1, sizeof dp);

        cout << "The minimum cutting is " << cut(0, n+1) << ".\n";
    }


    return 0;
}