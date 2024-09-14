#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;

    while (true) {

        cin >> n;
        if (n == 0)
            break;

        int max_here = 0;
        int max_sfar = 0;

        for (int i=0; i<n; i++) {
            cin >> k;
            max_here = max(k, max_here + k);
            max_sfar = max(max_sfar, max_here);
        }

        if (max_sfar > 0) {
            cout << "The maximum winning streak is " << max_sfar << ".\n";
        } else {
            cout << "Losing streak.\n";
        }

    }



    return 0;
}