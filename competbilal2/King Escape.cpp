#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
bool visited[1010][1010];
int n, ax, ay, bx, by, cx, cy;

void dfs(int x, int y) {

    int xx, yy;

    if (visited[x][y])
        return;

    visited[x][y] = true;

    for (int i=0; i<8; i++) {
        xx = x + dx[i];
        yy = y + dy[i];

        if (!visited[xx][yy] && xx >= 1 && xx <= n && yy >= 1 && yy <= n)
            dfs(xx, yy);
    }

}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    for (int i=n; i>=1; i--) {
         for (int j=n; j>=1; j--) {
            if (i == ax || j == ay || abs(i - ax) == abs(j - ay))
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }

    dfs(bx, by);
    if (visited[cx][cy])
        cout << "YES";
    else
        cout << "NO";

    // cout << ax << " ";
    // cout << ay << "\n";
    // cout << bx << " ";
    // cout << by << "\n";
    // cout << cx << " ";
    // cout << cy << "\n";

    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}