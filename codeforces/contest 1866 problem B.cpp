#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, result, ans, mod = 998244353;
    vector<int> x, y, xp, yp;
    int scan;
    map<int, int> xm, ym, joint;

    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &scan);
        x.push_back(scan);
    }

    
    for (int i=0; i<n; i++) {
        scanf("%d", &scan);
        xp.push_back(scan);
    }

    scanf("%d", &m);

    for (int i=0; i<m; i++) {
        scanf("%d", &scan);
        y.push_back(scan);
    }

    
    for (int i=0; i<m; i++) {
        scanf("%d", &scan);
        yp.push_back(scan);
    }

    for (int i=0; i<n; i++)
        xm[x[i]] = xp[i];

    for (int i=0; i<m; i++)
        ym[y[i]] = yp[i];

    // for (pair<int, int> facteurDeX: xm) {
    //     printf("%d:%d\n", facteurDeX.first, facteurDeX.second);
    // }
    // printf("\n");
    // for (pair<int, int> facteurDeY: ym) {
    //     printf("%d:%d\n", facteurDeY.first, facteurDeY.second);
    // }

    bool flag = 1;
    for (pair<int, int> facteurDeX: xm) {
        if (ym.count(facteurDeX.first) == 0)
            joint[facteurDeX.first] = facteurDeX.second;
        else if (facteurDeX.second < ym[facteurDeX.first])
            flag = 0;
        else
            joint[facteurDeX.first] = facteurDeX.second - ym[facteurDeX.first];
    }

    for (pair<int, int> facteurDeY: ym)
        if (xm.count(facteurDeY.first) == 0)
            flag = 0;

    // printf("\n");
    // for (pair<int, int> facteur: joint) {
    //     printf("%d:%d\n", facteur.first, facteur.second);
    // }

    if (flag == 0) 
        printf("0");
    else {
        result = 0;
        for (pair<int, int> elem: joint) {
            if (elem.second != 0) {
                result++;
            }
        }
        ans = 1;
        for (int i=1; i<=result; i++) {
            ans = ans * 2 % mod;
        }
        printf("%d", ans);
    }

    return 0;
}