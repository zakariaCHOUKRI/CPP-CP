#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int n, m;
string s;
vector<int> suff;
vector<int> corr;



int main() {

    sor3a

    cin >> n >> m;
    cin >> s;

    suff.resize(n, 0);
    corr.resize(n, 0);

    // for (int i=1; i<n; i++) {
        
    //     if (s[i] == 'C' && s[i-1] == 'A') {
    //         corr[i] = -1;
    //     }
    // }

    for (int i=0; i+1<n; i++) {
        
        if (s[i] == 'A' && s[i+1] == 'C') {
            suff[i] = 1;
            corr[i] = -1;
        }
    }

    for (int i=1; i<n; i++) {
        suff[i] += suff[i-1];
    }
    
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        a--;
        b--;
        if (a==0) {
            cout << suff[b] + corr[b] << "\n";
        } else {
            cout << suff[b] - suff[a-1] + corr[b]<< "\n";
        }
    }
    // cout << endl;
    // for (int i: suff) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i: corr) {
    //     cout << i << " ";
    // }


    return 0;
}