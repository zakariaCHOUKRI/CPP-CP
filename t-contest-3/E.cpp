#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, h, arr[200200], me, dla7, diff, diff2;

int main() {

    sor3a

    cin >> n >> h;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    me = -1;
    dla7 = 0;
    diff2 = 0;

    while (me < n-1) {
        
        while (arr[dla7] == 0 && dla7<n) {
            dla7++;
         
            if (dla7 == n-1) {
                break;
            }
        }

        if (dla7 == n-1) {
            diff = dla7 - me;
        
            // cout << h << endl;
            if (diff >= h) {
                // cout << h << " " << diff << endl;
                // cout << h << " ";
                cout << "NOhh";
                return 0;
            }
            else{
                cout << "YEhhS";
                return 0;
            }
        }

        arr[dla7] += diff2;

        diff = dla7 - me;
        
        // cout << h << endl;
        if (diff > h) {
            cout << h << " ";
            cout << "NO";
            return 0;
        }

        if (diff % 2 == 0) {
            diff2 = h - 2;
            cout << diff2 << " ";
            arr[dla7] += diff2;
            h = 1 +arr[dla7];
        }
        else {
            diff2 = h - 1;
            cout << h << endl;
            arr[dla7] += diff2;
            
            h = arr[dla7];
        }
        me = dla7;
        dla7++;
        // cout << me << " " << dla7 << " " << h << " " << diff << endl;

    }
    
    cout << "YES";


    return 0;
}