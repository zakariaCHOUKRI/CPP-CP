#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n;
    double r, res, a = (sqrt(2) - 1)/(sqrt(2) + 1);
    scanf("%d", &t);

    while (t--) {
        scanf("%lf %d", &r, &n);
        res = r * pow(a, n);
        printf("%f\n", res);
    }


    return 0;
}