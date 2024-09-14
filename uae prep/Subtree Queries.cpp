#include <bits/stdc++.h>

using namespace std;

int n, q, a, b, s, v, x, op;
vector<int> adj[200005];
int start[200005], finish[200005];
int values[200005];
int timer;

template <class T> class BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;

  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    void set(int ind, int val) {
        add(ind, val - arr[ind]);
    }

    void add(int ind, int val) {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind) {
            bit[ind] += val;
        }
    }

    T pref_sum(int ind) {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) {
            total += bit[ind];
        }
        return total;
    }
};

void dfs(int node, int parent) {

    start[node] = timer++;

    for (int neighbor: adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node);
        }
    }

    finish[node] = timer;

}

int main() {

    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> values[i];
    }

    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    timer = 0;
    dfs(0, -1);
    BIT<long long> bit(n);
	for (int i = 0; i < n; i++) {
        bit.set(start[i], values[i]);
    }

    for (int i=0; i<q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> s >> x;
            s--;
            bit.set(start[s], x);
        } else {
            cin >> s;
            s--;
            long long end_sum = bit.pref_sum(finish[s] - 1);
            long long start_sum;
            if (start[s] == 0) {
                start_sum = 0;
            } else {
                start_sum = bit.pref_sum(start[s] - 1);
            }
            cout << end_sum - start_sum << '\n';
        }
    }


    return 0;
}