#include <bits/stdc++.h>

using namespace std;

pair<int, int> cursor;
int keyboard[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 10}};
unordered_map<char, char> r90, r180, r270;

char parseChar(char where, int deg) {
    if (deg == 0) {
        return where;
    }
    else if (deg == 90) {
        return r90[where];
    }
    else if (deg == 180) {
        return r180[where];
    }
    else {
        return r270[where];
    }
}

void move(char where) {
    if (where == 'L') {
        if (cursor.second != 0) {
            cursor.second--;
        }
    }
    else if (where == 'R') {
        if (cursor.second != 2) {
            cursor.second++;
        }
    }
    else if (where == 'U') {
        if (cursor.first != 0) {
            cursor.first--;
        }
    }
    else if (where == 'D') {
        if (cursor.first != 3) {
            cursor.first++;
        }
    }
    else {
        if (keyboard[cursor.first][cursor.second] != 10)
            cout << keyboard[cursor.first][cursor.second];
    }
}

int main() {
    string seq;

    r90['L'] = 'D';
    r90['R'] = 'U';
    r90['U'] = 'L';
    r90['D'] = 'R';

    r180['L'] = 'R';
    r180['R'] = 'L';
    r180['U'] = 'D';
    r180['D'] = 'U';

    r270['L'] = 'U';
    r270['R'] = 'D';
    r270['U'] = 'R';
    r270['D'] = 'L';


    int n, degr, scen;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> degr >> scen;
        cout << i << '\n';
        for (int j=0; j<scen; j++) {
            cin >> seq;
            cursor = {1, 1};
            for (int k=0; k<seq.size(); k++) {
                move(parseChar(seq[k], degr));
            }
            cout << '\n';
        }
    }


    return 0;
}