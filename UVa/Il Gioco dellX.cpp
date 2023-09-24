// UVa 260 - Il Gioco dell’X

#include <bits/stdc++.h>

using namespace std;

int n, visited[210][210];
pair<int, int> directions[6] = {make_pair(-1, -1),
                                make_pair(-1, 0),
                                make_pair(0, -1),
                                make_pair(0, 1),
                                make_pair(1, 0),
                                make_pair(1, 1)};
char grid[210][210];

void dfs(int startX, int startY, char color) {

    visited[startX][startY] = 1;

    for (int i=0; i<6; i++)

        if (startX + directions[i].first < n &&
            startY + directions[i].second < n &&
            grid[startX + directions[i].first][startY + directions[i].second] == color &&
            !visited[startX + directions[i].first][startY + directions[i].second])

                dfs(startX + directions[i].first, startY + directions[i].second, color);
}

int main(){

    int found, count = 0;

    while (true) {

        cin >> n;
        if (n==0) break;

        found = 0;

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> grid[i][j];

        printf("%d ", ++count);

        memset(visited, 0, sizeof visited);
        for (int i=0; i<n; i++)
            if (grid[0][i] == 'b')
                dfs(0, i, 'b');

        for (int i=0; i<n; i++) {
            if (grid[n-1][i] == 'b' && visited[n-1][i] == 1) {
                printf("B\n");
                found = 1;
                break;
            }
        }


        memset(visited, 0, sizeof visited);
        for (int i=0; i<n; i++)
            if (grid[i][0] == 'w')
                dfs(i, 0, 'w');

        for (int i=0; i<n; i++) {
            if (grid[i][n-1] == 'w' && visited[i][n-1] == 1) {
                printf("W\n");
                break;
            }
        }

    }

    return 0;
}