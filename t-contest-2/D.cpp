#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main() {

    sor3a

    map<int, int> mx;
    map<int, int> my;


    int x, y;
    for (int i=0; i<3; i++) {

        cin >> x >> y;
        mx[x]++;
        my[y]++;

    }

    for (auto i: mx) {
        if (i.second % 2 == 1) cout << i.first << " ";
    }
    for (auto i: my) {
        if (i.second % 2 == 1) cout << i.first;
    }

    return 0;
}