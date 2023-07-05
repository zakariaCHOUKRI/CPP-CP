// UVa 11559 - Event Planning

#include <bits/stdc++.h>
using namespace std;


int main() {

    int N, B, H, W, p, a, cost;

    while(cin >> N >> B >> H >> W) {
        cost = 1 + B;
        for (int i=0; i<H; i++) {
            scanf("%d", &p);
            for (int j=0; j<W; j++) {
                scanf("%d", &a);
                if (a >= N && N * p <= cost) {
                    cost = N * p;
                }
            }
        }
        if (cost > B) printf("stay home\n");
        else printf("%d\n", cost);
    }

    

    return 0;
}
