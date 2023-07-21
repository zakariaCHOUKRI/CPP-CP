// UVa 10038 - Jolly Jumpers

#include <bits/stdc++.h>

using namespace std;

int main() {


    int n, input, arr[3001];
    bool flag[3001], found;

    while (cin >> n) {

        for (int i=0; i<n; i++) scanf("%d", &arr[i]);

        for (int i=1; i<n; i++) flag[i] = false;

        for (int i=1; i<n; i++) flag[abs(arr[i] - arr[i-1])] = true;

        found = 1;

        for (int i=1; i<n; i++) if (flag[i] == false) found = 0;

        //for (int i=1; i<n; i++) printf("|%d|", flag[i]);

        if (found == 1) printf("Jolly\n");
        else printf("Not jolly\n");



        
    }




    return 0;
}