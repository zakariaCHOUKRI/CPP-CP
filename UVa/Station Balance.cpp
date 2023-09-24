// UVa 410 - Station Balance

#include <bits/stdc++.h>

using namespace std;

int main(){

    int i, c, s, specimens[11], ptr;
    double imbalance, am, cmi;
    ptr = 0;


    while (scanf("%d %d", &c, &s) != EOF) {

        imbalance = 0;
        am = 0;

        ptr++;
        printf("Set #%d\n", ptr);

        for (i=0; i<s; i++) scanf("%d", &specimens[i]);
        //printf("dsmlfksdmflkjsd i = %d   c = %d    s = %d dsqoijfoijsgosifjg\n", i, c, s);
        while (i < 2*c) {
            specimens[i] = 0;
            i++;
        }

        sort(specimens, specimens + 2*c);
        for (i=0; i<2*c; i++) am += specimens[i];
        am /= (float) c;

        // for (i=0; i<2*c; i++) printf("%d ", specimens[i]);
        // printf("\n");

        for (i=0; i<c; i++) {
            cmi = 0;
            printf(" %d:", i);
            
            if (specimens[i] != 0) {
                printf(" %d", specimens[i]);
                cmi += specimens[i];
            }
            
            if (specimens[2*c - (i+1)] != 0) {
                printf(" %d", specimens[2*c - (i+1)]);
                cmi += specimens[2*c - (i+1)];
            }

            imbalance += abs(cmi - am);

            printf("\n");
        }

        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }

    return 0;
}