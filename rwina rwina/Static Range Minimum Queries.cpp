#include <bits/stdc++.h>

using namespace std;

int main() {

    int l, r, n, q;

    int arr[2005];
    int table[2005][20];

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++) {
        table[i][0] = arr[i];
    }

    for (int j=1; j<=(int) ceil(log2(n)); j++) {
        for (int i=1; i<=n; i++) {
            table[i][j] = min(table[i][j-1], table[i+(int)pow(2, j-1)][j-1]);
        }
    }


    for (int i=0; i<q; i++) {

        cin >> l >> r;
        int ans = INT32_MAX;
        for (int j=(int) ceil(log2(n)); j>=0; j--) {
            if (l + (int) pow(2, j) - 1 <= r) {
                ans = min(ans, table[l][j]);
                l = l + (int) pow(2, j);
            }
        }

        cout << ans << endl;
    }


    return 0;
}