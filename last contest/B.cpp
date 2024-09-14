#include <bits/stdc++.h>

#define sor3a ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

#define ii pair<int,int>

class UnionFind {

    private: vector<int> p, rank;
    public:
        UnionFind(int N) {
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i=0; i<N; i++) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) {
                    p[y] = x;
                }
                else {
                    p[x] = y;
                    if (rank[x] == rank[y]) {
                        rank[y]++;
                    }
                }
            }
        }
};



int main() {

    int n, m, u, v, w;
    cin >> n >> m;

    vector<pair<int, ii>> EdgeList;
    for (int i=0; i<m; i++) {
        cin >> u >> v >> w;
        EdgeList.push_back(make_pair(w, ii(u, v)));
    }
    sort(EdgeList.begin(), EdgeList.end());

    int mst_cost = 0;
    UnionFind UF(n);
    for (int i=0; i<m; i++) {
        pair<int, ii> front = EdgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }

    cout << "MST cost =" << mst_cost;



    return 0;
}