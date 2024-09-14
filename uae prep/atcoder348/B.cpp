#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x[105], y[105], d[105], dindex[105];
    cin >> n;


    memset(d, 0, sizeof d);

    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (d[i] < (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])) {
                d[i] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
                dindex[i] = j;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << dindex[i] << endl;
    }



    return 0;
}