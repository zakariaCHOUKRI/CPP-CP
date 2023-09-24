#include <bits/stdc++.h>

using namespace std;

char graph[1010][1010];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs() {}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    char cell;
    pair<int, int> start, finish;

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> cell;
            graph[i][j] = cell;
            if (cell == 'A')
                start = {i, j};
            else if (cell == 'B')
                finish = {i, j};
        }
    }

    



    return 0;
}