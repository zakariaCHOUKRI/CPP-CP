#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, a, d, l, r, att[1005], def[1005];

    cin >> t;

    for (int testCase=1; testCase<=t; testCase++) {

        cout << testCase << ". ";

        cin >> a >> d;

        for (int i=0; i<a; i++) {
            cin >> att[i];
        }

        sort(att, att+a, greater<int>());

        for (int i=0; i<d; i++) {
            cin >> def[i];
        }

        sort(def, def+d, greater<int>());

        l = 0;
        r = 0;

        for (int i=0; i<min(a,d); i++) {
            if (att[i] > def[i]) {
                r++;
            }
            else {
                l++;
            }
        }

        cout << l << " " << r << "\n";



    }



    return 0;
}