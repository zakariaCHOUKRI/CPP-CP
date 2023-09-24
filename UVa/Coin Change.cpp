// UVa 674 - Coin Change

#include <bits/stdc++.h>

using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int ways[7490];

int main() {

    int inp;
    ways[0] = 1;

    for (int i = 0; i<5; i++) for (int j = coins[i]; j<7490; j++) ways[j] += ways[j - coins[i]];

    while (scanf("%d", &inp) != EOF) printf("%d\n", ways[inp]);

    return 0;
}