#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    string s;
    int count0 = 0, count1=0;

    cin >> s;

    for (char c: s) {
        if(c == '0') {
            count0++;
        }
        else {
            count1++;
        }
    }

    cout << abs(count0 - count1);

    return 0;
}