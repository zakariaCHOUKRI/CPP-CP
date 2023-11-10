#include<bits/stdc++.h>

using namespace std;

string getBinaryRepresentation(int n) {
    string binary = "";
    for(int i = 23; i >= 0; i--) {
        if(n & (1 << i)) {
            binary += "1";
        } else {
            binary += "0";
        }
    }
    return binary;
}

int minOf3(int a, int b, int c) {
    return min(min(a,b),c);
}

int main() {

    int d, r, k=1;
    string ds, rs;
    map<int, int> m;
    

    while (true) {

        cin >> d >> r;

        if (d==0 && r==0)
            break;

        cout << k++ << ". ";

        ds = getBinaryRepresentation(d);
        rs = getBinaryRepresentation(r);

        // cout << endl << ds << endl << rs << endl;

        m[0] = 0;
        m[10] = 0;
        m[11] = 0;
        m[1] = 0;


        for (int i=0; i<24; i++) {

            if (ds[i] == '1' && rs[i] == '1') {
                m[11] += 1;
            }

            else if (ds[i] == '1' && rs[i] == '0') {
                m[10] += 1;
            }

            else if (ds[i] == '0' && rs[i] == '0') {
                m[0] += 1;
            }

            else if (ds[i] == '0' && rs[i] == '1') {
                m[1] += 1;
            }

        }

        // cout << "00: " << m[0] << endl;
        // cout << "10: " << m[10] << endl;
        // cout << "11: " << m[11] << endl;
        // cout << "01: " << m[1] << endl;

        cout << minOf3(m[10]+m[0]+1, m[11]+m[1]+1, m[10]+m[1]) << endl;

    }


}