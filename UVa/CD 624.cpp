// UVa 624 - CD

#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int t[21];
vector<int> sol, best;


void calc(int i, int cur) {
    if (i==m) {
        if (cur > ans) {
            ans = cur;
            best.clear();
            for (int x: sol) best.push_back(x);
        }
        return;
    }

    calc(i+1, cur);

    if (t[i] + cur <= n) {
        sol.push_back(t[i]);
        calc(i+1, cur + t[i]);
        sol.pop_back();
    }
}



int main(){

    while (scanf("%d", &n) != EOF) {
        scanf("%d", &m);
        for(int i=0; i<m; i++) scanf("%d", &t[i]);

        sol.clear();
        best.clear();
        ans = 0;

        calc(0, 0);
        for (int x: best) printf("%d ", x);
        printf("sum:%d\n", ans);
    }
    return 0;
}