#include<bits/stdc++.h>

#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int k, h, s, n, l[1005], diff[1005], curr;

int main() {

    sor3a

    cin >> k;

    for (int testCase=1; testCase<=k; testCase++) {

        cin >> h >> s >> n;

        for (int i=0; i<n; i++) {
            cin >> l[i];
        }

        curr = l[1];

        int idx = 1;

        if (curr > s){
            cout << testCase << ". " << l[0] << "\n";
            continue;
        }

        while (curr < s && idx < n-1) {

            curr = abs(l[idx+1] - l[idx-1]);
            idx++;
            // cout << idx << "--" << endl;

        }

        if (idx == n-1) {
            if (h-l[n-2] > s) {
                cout << testCase << ". " << l[n-1] << "\n" ;
            }
            else {
                cout << testCase << ". " << "Not possible\n";
            }
        }
        else {
            cout << testCase << ". " << l[idx] << "\n";
        }


    }

    return 0;

}