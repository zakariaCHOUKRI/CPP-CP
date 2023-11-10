#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    int t, n, a[100010], b[100010], x, y, ans, idx;
    bool breake;

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);

        breake = 0;
        for (int i=0; i<n; i++) {
            if (breake) break;
            b[i] = 0;
            idx = i;
            for (int j=i+1; j<n; j++) {
                x = a[i] & a[j];
                y = a[i] ^ a[j];
                if (x >= y)
                    b[i] += 1;
                if (b[i] == n-1) {
                    breake = 1;
                    break;
                }
            }
        }

        ans = 0;
        for (int i=0; i<idx+1; i++)
            ans = max(ans, b[i]);

        printf("%d\n", ans+1);

    }


}