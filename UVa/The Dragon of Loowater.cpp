// UVa 11292 - The Dragon of Loowater

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, d[20005], k[20005], dp, kp, gold;

    while (true) {

        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (int i=0; i<n; i++) scanf("%d", &d[i]);
        for (int i=0; i<m; i++) scanf("%d", &k[i]);

        sort(d, d + n);
        sort(k, k + m);

        gold = dp = kp = 0;

        while (dp < n && kp < m) {

            while (d[dp] > k[kp] && kp < m) kp++;

            if (kp == m) break;

            gold += k[kp];

            dp++;
            kp++;
        }

        if (dp == n) printf("%d\n", gold);
        else printf("Loowater is doomed!\n");
    }

    return 0;
}