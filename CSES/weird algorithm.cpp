// https://cses.fi/problemset/task/1068

#include <cstdio>

int main() {

    long long n;
    scanf("%lld", &n);
    while (n - 1) {
        printf("%lld ", n);
        if (n%2) n = 3*n + 1;
        else n /= 2;
    }
    printf("%lld ", n);

    return 0;
}