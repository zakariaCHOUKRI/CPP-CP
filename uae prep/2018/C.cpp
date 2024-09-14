#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr, vis, res;

bool isSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
}

bool stop ;

void dfs(int cnt, int last) {

    if (stop) {
        return;
    }

    if (cnt == n) {
        for (int i=0; i<n; i++) {
            cout << res[i] << " ";
        }
        stop = true;
    }

    for (int i=0; i<n; i++) {
        if (vis[i] == 0) {
            if (isSquare(last + arr[i])) {
                res.push_back(arr[i]);
                vis[i] = 1;
                dfs(cnt + 1, arr[i]);
                vis[i] = 0;
                res.pop_back();
            }
        }
    }
}

int main() {

    while (true) {
        cin >> n;
        stop = false;
        if (n==0) {
            break;
        }

        arr.resize(n);
        res.clear();
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        for (int i=0; i<n; i++) {
            res.push_back(arr[i]);
            vis.resize(n, 0);
            vis[i] = 1;
            dfs(1, arr[i]);
            vis[i] = 0;
            res.pop_back();
        }

        cout << endl;

    }

    return 0;
}