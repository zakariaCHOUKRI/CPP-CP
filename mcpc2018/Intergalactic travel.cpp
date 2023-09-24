#include <bits/stdc++.h>

using namespace std;

int main() {

    int path[100], distance[100];
    int t, n, l, r, u, j, size, vertex;
    queue<int> q;
    int adjList[100][100];

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);

        for (int i=1; i<=n; i++) {
            scanf("%d %d", &l, &r);
            adjList[i][0] = r-l+1;
            for (int j=1; j<=adjList[i][0]; j++)
                adjList[i][j] = l + j - 1;
        }

        // for(int i=1; i<=n; i++) {
        //     printf("%d: ", i);
        //     for (int j=1; j<=adjList[i][0]; j++)
        //         printf("%d, ", adjList[i][j]);
        //     printf("\n");
        // }

        // printf("\n");

        memset(distance, -1, sizeof distance);

        distance[1] = 0;
        path[1] = 1;

        while(!q.empty()) q.pop();
        q.push(1);
        while(!q.empty()) {

            size = q.size();

            while(size-->0) {

                vertex = q.front();
                q.pop();

                for (int i=1; i<=adjList[vertex][0]; i++) {

                    if (distance[adjList[vertex][i]] == -1) {

                        distance[adjList[vertex][i]] = distance[vertex] + 1;
                        path[adjList[vertex][i]] = vertex;
                        q.push(adjList[vertex][i]);

                    }
                }
            }
        }

        printf("%d\n", distance[n]);


    }

    return 0;
}