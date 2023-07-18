// UVa 10684 - The jackpot

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, bet, meh, msf;

    while (true) {

        scanf("%d", &n);
        if (n==0) break;

        meh = 0;
        msf = -1001;
        for (int i=0; i<n; i++) {
            scanf("%d", &bet);
            meh = meh + bet;
            if (meh < bet) meh = bet;
            if (msf < meh) msf = meh;
        }
        
        if (msf > 0) printf("The maximum winning streak is %d.\n", msf);
        else printf("Losing streak.\n");

    }

    return 0;
}