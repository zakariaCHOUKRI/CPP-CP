#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, x[250005], y[250005];
    int test[20][20];

    for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
            test[i][j] = (i+j) % 3;
        }
    }

    for (int i=1; i<10; i++) {
        for (int j=1; j<10; j++) {
            cout << test[i][j] << " ";
        }
        cout << '\n';
    }

    while (true) {

        cin >> n;
        if (n == 0)
            break;

        for (int i=0; i<n; i++) {
            cin >> x[i];
        }

        for (int i=0; i<n; i++) {
            cin >> y[i];
        }


    }



    return 0;
}