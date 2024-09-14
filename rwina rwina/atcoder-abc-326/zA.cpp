#include <bits/stdc++.h>

using namespace std;

int main() {

    int x, y;
    cin >> x >> y;
    if (x-y == 1 || x-y == 2 || x-y == -1 || x-y == -2 || x-y == 3) {
        cout << "Yes";
    } else {
        cout << "No";
    }



    return 0;
}