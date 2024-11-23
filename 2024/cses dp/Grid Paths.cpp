#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int n; ll dp[1005][1005];
char grid[1005][1005];


ll answer(int x, int y) {
    if (x==0 && y==0) {
        return 1;
    }

    if (dp[x][y]) {
        return dp[x][y];
    }

    ll res = 0;
    
    if (x-1 >= 0 && grid[x-1][y] != '*') {
        res = (res + answer(x-1, y)) % mod;
    }

    if (y-1 >= 0 && grid[x][y-1] != '*') {
        res = (res + answer(x, y-1)) % mod;
    }

    dp[x][y] = res;

    return res;

}

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(dp, 0, sizeof dp);

    if (grid[0][0] == '*' || grid[n-1][n-1] == '*') {
        cout << 0 << endl;
    } else {
        if (n == 1) {
            cout << 1 << endl;
        } else { 
            
            dp[0][0] = 1;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    ll res = 0;
                    if (i-1 >= 0 && grid[i-1][j] != '*') {
                        res = (res + dp[i-1][j]) % mod;
                    }

                    if (j-1 >= 0 && grid[i][j-1] != '*') {
                        res = (res + dp[i][j-1]) % mod;
                    }

                    dp[i][j] = res;
                }
            }
            cout << dp[n-1][n-1] << endl;
        }
    }

    return 0;
}