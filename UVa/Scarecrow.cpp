// UVa 12405 - Scarecrow

#include <bits/stdc++.h>

using namespace std;

int main() {

    int T, N, ns;
    string field;

    scanf("%d", &T);

    for (int u=1; u<=T; u++){

        scanf("%d", &N);
        cin >> field;

        ns = 0;
        for (int i=0; i<N; i++) {
            if (field[i] == '.') {
                i++;
                ns++;
                i++;
            }
        }

        printf("Case %d: %d\n", u, ns);




    }

    return 0;
}