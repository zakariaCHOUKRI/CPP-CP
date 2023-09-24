#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, h, monsters[110], cost, oneCount;

    cin >> t;
    while (t--) {

        cin >> n;
        oneCount = 0;
        for (int i=0; i<n; i++) {
            cin >> h;
            if (h == 1) oneCount++;
            monsters[i] = h;
        }

        // for (int i=0; i<n; i++)
        //     cout << monsters[i] << " ";
        // cout << "\n";

        cost = n-oneCount + oneCount/2 + (oneCount%2);
        cout << cost << "\n";
    }

    return 0;
}