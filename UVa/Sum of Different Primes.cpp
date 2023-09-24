// UVa 1213 - Sum of Different Primes

#include <bits/stdc++.h>

using namespace std;

int n, k, primes[1121], pt, memo[1121][15];

void sieve() {

    bool mark[1121]; // marks primes with 0 and non primes with 1
    pt = 0;

    memset(mark, 0, sizeof mark);

    for (int i=2; i<1120; i++) {

        if (mark[i] == 0) {

            primes[pt] = i;
            pt++;

            for (int j=2; i * j < 1120; j++) mark[i*j] = 1;
        }
    }
}

void build() {

    memo[0][0] = 1;

    for (int i=0; i<pt; i++) {
        for (int j = 1120; j >= primes[i]; j--) {
            for (int k = 14; k >= 1; k--) {
                memo[j][k] += memo[j - primes[i]][k - 1];
            }
        }
    }

}

int main() {

    sieve();
    build();

    while (true) {

        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;

        printf("%d\n", memo[n][k]);



    }
    return 0;
}