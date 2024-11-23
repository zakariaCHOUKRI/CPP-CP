#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, coins[105];
bool dp[105][100005];


int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }

    dp[0][0] = true;

    for (int i=1; i<=n; i++) {
        for (int j=0; j<100005; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - coins[i-1] >= 0 && dp[i-1][j - coins[i-1]]) {
                dp[i][j] = true;
            }
        }
    }

    set<int> s;
    for (int i=1; i<100005; i++) {
        if (dp[n][i]) {
            s.insert(i);
        }
    }

    cout << s.size() << endl;
    for (int elem: s) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}