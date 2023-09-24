#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1, 0}; 
int dy[4] = {0,1, 0,-1};
int n, m;
char house[1010][1010], cell;
bool visited[1010][1010];

void floodfill(int x, int y) {

    int newX, newY;

    visited[x][y] = true;
    for (int d=0; d<4; d++) {
        newX = x+dx[d];
        newY = y+dy[d];

        if (!visited[newX][newY] && newX >= 0 && newY >= 0 && newX < n && newY < m)
            floodfill(newX, newY);
    }
}


int main(){

    int count;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            cin >> cell;
            house[i][j] = cell;
            if (cell == '#')
                visited[i][j] = true;
        }

    count = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j]) {
                count++;
                floodfill(i, j);
            }
        }
    }

    cout << count;

    return 0;
}