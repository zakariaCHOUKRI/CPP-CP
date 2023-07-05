// UVa 11799 - Horror Dash

#include <bits/stdc++.h>
using namespace std;

int main() {

    int T, N, c;

    scanf("%d", &T);

    for(int i=1; i<=T; i++) {
        int speed = -1;
        scanf("%d", &N);
        while (N--) {
            scanf("%d", &c);
            if (c > speed) speed = c;
        }
        printf("Case %d: %d\n", i, speed);
    }

    return 0;
}
