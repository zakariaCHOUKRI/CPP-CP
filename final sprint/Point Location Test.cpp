#include <bits/stdc++.h>

using namespace std;

long long formula(long long a, long long b, long long c, long long d, long long e, long long f) {
    return (f - b)*(c - a) - (e - a)*(d - b);
}

int main() {

    long long a, b, c, d, e, f;
    long long t;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> e >> f;
        long long formule = formula(a, b, c , d, e, f);
        if (formule == 0) {
            cout << "TOUCH\n";
        }
        else if (formule > 0) {
            cout << "LEFT\n";
        }
        else {
            cout << "RIGHT\n";
        }
    }



    return 0;
}