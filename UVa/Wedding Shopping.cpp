// UVa 11450 - Wedding Shopping

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k, m, c, money, prices[25][25];
    bool reachable[25][210];

    scanf("%d", &n);

    while (n--) {

        scanf("%d %d", &m, &c);

        for (int i=0; i<c; i++) {
            scanf("%d", &prices[i][0]);
            for (int j=1; j<= prices[i][0]; j++) {
                scanf("%d", &prices[i][j]);
            }
        }

        memset(reachable, false, sizeof reachable);

        for (int i=1; i <= prices[0][0]; i++) 
            if (m - prices[0][i] >= 0)
                reachable[0][m - prices[0][i]] = true;

        for (int i=1; i<c; i++) 
            for (money = 0; money < m; money++) 
                if (reachable[i-1][money])
                    for (k=1; k<=prices[i][0]; k++)
                        if (money - prices[i][k] >= 0)
                            reachable[i][money - prices[i][k]] = true;

        for (money=0; money <= m && !reachable[c-1][money]; money++);

        if (money == m + 1) printf("no solution\n");
        else printf("%d\n", m - money);

    }


    return 0;
}