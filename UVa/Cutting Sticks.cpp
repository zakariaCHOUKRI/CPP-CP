// UVA 10003 - Cutting Sticks

#include <bits/stdc++.h>

using namespace std;

int l, n, A[55], memo[53][53];

int cut(int left, int right) {

    if (left + 1 == right) return 0;
    if (memo[left][right] != -1) return memo[left][right];

    int mini = INT32_MAX;
    for (int i=left+1; i<right; i++) 
        mini = min(mini, cut(left, i) + cut(i, right) + A[right] - A[left]);
    memo[left][right] = mini;
    return mini;

}

int main() {

    while (true) {

        scanf("%d", &l);
        if (l == 0) break;

        scanf("%d", &n);

        A[0] = 0;
        for (int i=1; i<=n; i++) scanf("%d", &A[i]);
        A[n+1] = l;

        memset(memo, -1, sizeof memo);
        printf("The minimum cutting is %d.\n", cut(0, n+1));
    }
    return 0;
}