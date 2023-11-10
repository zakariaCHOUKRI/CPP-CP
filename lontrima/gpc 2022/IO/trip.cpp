#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, e, n, ni;
    map<int, int> m;
    bool flag;

    cin >> t;

    for (int k=1; k<=t; k++) {

        m.clear();
        flag = false;

        cin >> e;
        for (int j=0; j<e; j++) {
            cin >> n;
            for (int i=0; i<n; i++) {
                cin >> ni;
                m[ni] += 1;
            }
        }

        cout << k << ". ";

        for (auto elem: m) {
            if (elem.second == e && flag == false) {
                flag = true;
                cout << elem.first;
            }
            else if (elem.second == e && flag == true) {
                cout << "," << elem.first;
            }
        }
        
        if (flag == false) {
            cout << "No Trip";
        }


        cout << "\n";




    }




    return 0;
}