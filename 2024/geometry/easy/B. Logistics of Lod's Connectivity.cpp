#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int n;
    double a, b, x, y, pi = 3.14159265358979323846;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf", &a, &b);
        a = (2.0*pi*a)/360.0;
        x += b * cos(a);
        y += b * sin(a);
    }
    a = sqrt(x*x + y*y);
    printf("%f\n", a);
 
    return 0;
}