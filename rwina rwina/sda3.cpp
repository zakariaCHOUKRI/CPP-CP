#include <bits/stdc++.h>
#define iii pair<pair<int, int>, int>

using namespace std;

int link[1000], sizes[1000];
vector<iii> edgeList;
int n, m, a, b, w;
map<pair<int, int>, int> edgeWeights;

int find(int x) {

    while (x != link[x]) {
        x = link[x];
    }

    return x;
}

int same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {

    x = find(x);
    y = find(y);

    if (sizes[x] < sizes[y]) {
        swap(x, y);
    }

    sizes[x] += sizes[y];
    link[y] = x;
}

int main() {

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> w;
        edgeList.push_back(make_pair(make_pair(a, b), w));
        edgeWeights[make_pair(a, b)] = w;
    }

    sort(edgeList.begin(), edgeList.end(), [](iii a, iii b){ return a.second < b.second; });
    // for (iii edge: edgeList) {
    //     cout << edge.first.first << "-" << edge.first.second << ": " << edge.second << endl;
    // }

    for (int i=1; i<=n; i++) {
        link[i] = i;
        sizes[i] = 1;
    }

    int mst = 0;

    for (iii edge: edgeList) {
        if (!same(edge.first.first, edge.first.second)) {
            unite(edge.first.first, edge.first.second);
            mst += edge.second;
        }
    }

    // for (int i=1; i<=n; i++) {
    //     cout << "link[" << i << "] = " << link[i] << " ";
    //     cout << "sizes[" << i << "] = " << sizes[i] << endl;
    // }

    cout << "the mst is: " << mst << endl;

    return 0;
}