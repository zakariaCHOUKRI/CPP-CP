// UVa 12150 - Pole Position

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, c, p;
    long long ranking[1001];
    bool good;

    while (true) {

        scanf("%lld", &n);
        if (n==0) break;

        good = true;
        memset(ranking, -1, sizeof(ranking));

        for (int i=1; i<=n; i++) {

            scanf("%lld %lld", &c, &p);

            if (i + p < 1 || i + p > n) good = false;

            else if (ranking[i+p] == -1) ranking[i+p] = c; 
            else good = false;

        }

        
        if (good) {
            printf("%lld", ranking[1]);
            for (int i=2; i<=n; i++) printf(" %lld", ranking[i]);
        }
        else printf("-1");
        printf("\n");
    }


    return 0;
}