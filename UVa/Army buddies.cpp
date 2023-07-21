// UVa 12356 - Army buddies

#include <bits/stdc++.h>

using namespace std;

int main() {


    int s, b, l, r;
    int left[100005], right[100005];

    while (true) {

        scanf("%d %d", &s, &b);
        if (s==0 && b==0) break;

        for (int i=1; i<=s; i++) {
            left[i] = i-1;
            right[i] = i+1;
        }

        right[s] = -1;
        left[1] = -1;

        while (b--) {
            scanf("%d %d", &l, &r);

            left[right[r]] = left[l];
            if (left[l] == -1) printf("*");
            else {
                printf("%d", left[l]);
            }

            printf(" ");

            right[left[l]] = right[r];
            if (right[r] == -1) printf("*");
            else {
                printf("%d", right[r]);
            }

            printf("\n");
        }

        printf("-\n");


    }





    return 0;
}