// UVa 11902 - Dominator

#include <bits/stdc++.h>

using namespace std;

int t, n, adjMatrix[101][101], visited[101], visited2[101], f[101][101];

void dfs(int start, int ignore) {

    if (start == ignore) return;

    visited[start] = 1;

    for (int i=0; i<n; i++)
        if (adjMatrix[start][i] == 1 && !visited[i])
            dfs(i, ignore);
}

int main(){

    scanf("%d", &t);
    for (int ijk=1; ijk<=t; ijk++) {

        scanf("%d", &n);
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                scanf("%d", &adjMatrix[i][j]);

        memset(visited, 0, sizeof visited);

        dfs(0, -1);

        for(int i=0; i<n; i++) visited2[i] = visited[i];

        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < n; j++)
                visited[j] = 0;
            
            dfs(0, i);
            for(int j = 0; j < n; j++)
                if(visited2[j] && !visited[j])
                    f[i][j] = 1;
                else
                    f[i][j] = 0;
            f[i][i] = visited2[i];

        }

        printf("Case %d:\n", ijk);

        putchar('+');
        for(int i = -n+1; i < n; i++)
            putchar('-');
        puts("+");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                putchar('|');
                putchar(f[i][j] ? 'Y' : 'N');
            }
            puts("|");
            putchar('+');
            for(int j = -n+1; j < n; j++)
                putchar('-');
            puts("+");
        }


    }

    return 0;
}