#include <bits/stdc++.h>

using namespace std;

const int mx = 15000;
int tri[mx];

void generate() {
    tri[0] = 0;
    for (int i=1; i<mx; i++) {
        tri[i] = tri[i-1] + i;
    }
}

bool linearSolve(int n) {
    for (int i=0; i<mx; i++) {
        if (tri[i] == n) {
            return true;
        }
    }
    return false;
}

void solve(int idx) {
    int n;
    int l, r;
    cin >> n;

    if (linearSolve(n)) {
        cout << idx << ". " << n << endl;
        return;
    }

    for (int i=0; i<mx; i++) {
        
        l = i;
        r = mx-1;

        int sm = tri[l] + tri[r];
        int target = n - tri[i];
        while (l <= r) {
            if (target < sm) {
                r--;
                sm = tri[l] + tri[r];
            }
            else if (target > sm) {
                l++;
                sm = tri[l] + tri[r];
            }
            else {
                if (tri[i] == 0) {
                    cout << idx << ". " << tri[l] << " " << tri[r] << endl;
                    return;
                }
                cout << idx << ". " << tri[i] << " " << tri[l] << " " << tri[r] << endl;
                return;
            }
        }
    }

}

int main() {
    
    generate();
    int T;
    cin >> T;

    for (int i=1; i<T+1; i++) {
        solve(i);
    }

    return 0;
}
