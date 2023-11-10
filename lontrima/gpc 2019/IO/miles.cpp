#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, v, arr[500050], k=1, inp, maxi, p1, p2;

    while (true) {

        cin >> m >> v;

        if (m == 0 && v == 0)
            break;

        maxi=-1;
        cout << k++ << ". ";

        cin >> arr[0];

        for (int i=1; i<m; i++) {
            cin >> inp;
            arr[i] = arr[i-1] + inp;
        }

        if (v >= m) {
            cout << arr[m-1] << endl;
            continue;
        }


        p1 = 0;
        p2 = p1 + v;

        while (p2 < m) {
            maxi = max(maxi, arr[p2] - arr[p1]);
            p1++;
            p2++;
        }

        cout << maxi << endl;

    }




    return 0;
}