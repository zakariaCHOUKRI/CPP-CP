#include <bits/stdc++.h>

using namespace std;

bool safe(int a, int b) {
    if (a > b) {
        swap(a, b);
    }

    return ((b-a) % 2 == 0);
}

int main() {

    int n, a, b;
    cin >> n;

    for (int i=1; i<n+1; i++) {
        cin >> a >> b;
        if (safe(a, b)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}