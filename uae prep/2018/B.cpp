#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, c, arr[1005], sum;

    cin >> t;
    for (int i=1; i<=t; i++) {


        sum = 0;
        cin >> c;
        for (int j=0; j<c; j++) {
            cin >> arr[j];
            sum += arr[j];
        }

        if (sum == c) {
            cout << i << ". Impossible\n";
        } else {
            int res = c + 1;
            cout << i << ". " << res << "\n";
        }

    }



    return 0;
}