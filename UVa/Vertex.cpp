// UVa 280 - Vertex

#include <bits/stdc++.h>

using namespace std;

int n, edge1, edge2, howMany, edges[120], visited[120];
vector<pair<int, int>> edgeList;

void dfs(int start) {

    for (int i=0; i<edgeList.size(); i++) 
        if (edgeList[i].first == start && !visited[edgeList[i].second]) {
            visited[edgeList[i].second] = 1;
            dfs(edgeList[i].second);
        }
}

int main(){

    while (true) {

        edgeList.clear();

        scanf("%d", &n);
        if (n==0) break;

        while (true) {

            scanf("%d", &edge1);
            if (edge1 == 0) break;

            while (true) {
                scanf("%d", &edge2);
                if (edge2 == 0) break;
                edgeList.push_back(make_pair(edge1, edge2));
            }
        }

        scanf("%d", &howMany);
        for (int i=0; i<howMany; i++) scanf("%d", &edges[i]);

        for (int i=0; i<howMany; i++) {

            memset(visited, 0, sizeof visited);
            dfs(edges[i]);

            int count = 0;
            for (int j=1; j<=n; j++) if (!visited[j]) count++;

            printf("%d", count);
            for (int j=1; j<=n; j++) if (!visited[j]) printf(" %d", j);

            printf("\n");
        }

    }

    return 0;
}