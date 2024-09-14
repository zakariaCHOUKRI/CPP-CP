#include <iostream>
#include <cstring>

using namespace std;

int main() {

    string r1, r2, r3, r4, p1, p2;
    int t, norows, m[10], sume;

    cin >> t;
    while (t--) {

        cin >> r1 >> r2 >> r3 >> r4 >> p1 >> p2;

        norows = 0;
        sume = 0;
        memset(m, 0, sizeof m);

        for (int i=0; i<r1.size(); i++) {
            if (r1[i] == 'O') {
                m[1]++;
            }
        }

        for (int i=0; i<r2.size(); i++) {
            if (r2[i] == 'O') {
                m[2]++;
            }
        }

        for (int i=0; i<r3.size(); i++) {
            if (r3[i] == 'O') {
                m[3]++;
            }
        }

        for (int i=0; i<r4.size(); i++) {
            if (r4[i] == 'O') {
                m[4]++;
            }
        }

        bool atmostone = true;
        for (int i = 1; i <= 4; i++) {
            if (m[i] > 1) {
                atmostone = false;
                break;
            }
        }

        for (int i = 1; i <= 4; i++) {
            norows ^= m[i];
            sume += m[i];
        }

        if (!atmostone) {
            if (norows != 0) {
                cout << p1 << endl;
            } else {
                cout << p2 << endl;
            }
        } else {

            if (sume % 2 == 0) {
                cout << p1 << endl;
            } else {
                cout << p2 << endl;
            }
        }
    }

    return 0;
}
