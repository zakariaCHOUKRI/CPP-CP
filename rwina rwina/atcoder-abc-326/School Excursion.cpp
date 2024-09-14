#include <bits/stdc++.h>

using namespace std;

struct DSU {

    vector<int> e;

    void init(int N) {
        e = vector<int>(N, -1);
    }

    int get(int x) {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool sameset(int a, int b) {
        return get(a) == get(b);
    }

    int size(int x) {
        return -e[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);

        if (x==y) {
            return 0;
        }

        if (e[x] > e[y]) {
            swap(x, y);
        }

        e[x] += e[y];
        e[y] = x;

        return 1;
    }

};

DSU D;
int n, m;
vector<int> comps;

void init() {

    cin >> n >> m;

    D.init(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        D.unite(a-1, b-1);
    }

    for (int i=0; i<n; i++) {
        if (D.get(i) == i) {
            comps.push_back(D.size(i));
        }
    }
}

int main() {

    init();

    bitset<100001> posi;
    posi[0] = 1;
    for (int t : comps) posi |= posi << t;
    for (int i = 1; i <= n; ++i) cout << posi[i];



    return 0;
}