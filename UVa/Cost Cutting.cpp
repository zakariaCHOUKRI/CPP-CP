// UVa 11727 - Cost Cutting

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c;
    scanf("%d", &t);

    for (int i=0; i < t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: ", i+1);
        
        if ((a >= b && a <= c) || (a <= b && a >= c)) {
            printf("%d", a);
        } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
            printf("%d", b);
        } else {
            printf("%d", c);
        }
        printf("\n");
    }

    return 0;
}
