#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int euclide(int a, int b) {

    int tmp, r;

    if (b > a) {
        tmp = b;b = a;a = tmp;
    }

    if (b == 1) return 1;

    r = a % b;

    while (r) {
        a = b;
        b = r;
        r = a % b;
    } 

    return b;

}

int main() {

    sor3a

    int t, n, a[100010], m, ans, b[100010];

    scanf("%d", &t);
    while (t--) {

        scanf("%d %d", &n, &m);

        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);

        sort(a, a+n);

        ans = m;

        for (int j=1; j<=m; j++) {

            for (int i=0; i<n; i++) {
                printf("euclide(%d, %d) = %d\n", a[i], j, euclide(a[i], j));
                if (euclide(a[i], j) != 1) {
                    ans = ans - 1;
                    break;
                }
            }
        }

        printf("%d\n", ans);


    }


}