#include <bits/stdc++.h>

using namespace std;

int n, m, a, x, y, ans, consecutive, maxConsecutive;
bool cats[100010], visited[100010];
int consecutiveUpToHere[100010];
vector<int> tree[100010];
unordered_set<int> leaves;


void dfs(int start, int parent) {

    if (visited[start])
        return;

    if (start != 1) {

        if (cats[start] && cats[parent]) {
            consecutive++;
            maxConsecutive = max(maxConsecutive, consecutive);
        } else if (cats[start] && !cats[parent]) {
            consecutive = 1;
        } else {
            consecutive = 0;
        }

    } else {
        consecutive = cats[1];
    }

    consecutiveUpToHere[start] = maxConsecutive;

    visited[start] = true;

    for (int child: tree[start]) {
        if (!visited[child]) {
            dfs(child, start);
        }
    }

    if (leaves.count(start) == 1) {
        maxConsecutive = -1;
    }

    consecutive = consecutiveUpToHere[parent];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> a;
        cats[i] = a;
    }

    for (int i=1; i<n; i++) {
        cin >> x >> y;
        tree[x].push_back(y);
    }

    ans = 0;
    int numberOfLeaves = 0;
    for (int i=1; i<=n; i++)
        if (tree[i].size() == 0)
            leaves.insert(i);

    // cout << leaves.size() << "\n";
    // for (int leave: leaves)
    //     cout << leave << " ";

    maxConsecutive = cats[1];
    dfs(1, -1);

    ans = leaves.size();
    for (int leaf: leaves)
        if (consecutiveUpToHere[leaf] > m)
            ans--;

    cout << ans << "\n";

    for (int i=1; i<=n; i++)
        cout << consecutiveUpToHere[i] << " ";

    return 0;
}