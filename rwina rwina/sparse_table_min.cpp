#include <bits/stdc++.h>

using namespace std;

int main() {

    int l, r;

    const int N = 16;
    const int LOG = ceil(log2(N));

    int arr[N+1];
    int table[N+1][LOG+1];

    for (int i=1; i<=N; i++) {
        table[i][0] = arr[i];
    }

    for (int j=1; j<=LOG; j++) {
        for (int i=1; i<=N; i++) {
            table[i][j] = min(table[i][j-1], table[i+(int)pow(2, j-1)][j-1]);
        }
    }


    int ans = INT32_MAX;
    for (int j=LOG; j>=0; j--) {
        if (l + (int) pow(2, j) - 1 <= r) {
            ans = min(ans, table[l][j]);
            l = l + (int) pow(2, j);
        }
    }

    cout << ans << endl;

    return 0;
}