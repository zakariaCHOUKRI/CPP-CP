#include <bits/stdc++.h>

using namespace std;

int main() {

    long long n, res;
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        res = 2 + 3*((((n-1)/3) * (((n-1)/3) + 1))) - ((n-1)/3) - 1;
        cout << res << endl;
    }

    return 0;
}