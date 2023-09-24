#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, t, a, pointer1, pointer2, mini, sum, maxPtD;
    vector<int> books, arr;

    scanf("%d %d", &n, &t);
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        books.push_back(a);
    }

    mini = INT32_MAX;
    for (int i=0; i<n; i++)
        mini = min(mini, books[i]);

    if (mini > t)
        printf("0");
    else if (mini == t)
        printf("1");
    else {

        pointer1 = 0;
        pointer2 = 0;
        sum = 0;
        maxPtD = -1;

        while (pointer1 < n) {

            if (pointer2 == n-1 && pointer2 - pointer1 + 1 < maxPtD)
                break;

            if (sum + books[pointer2] > t) {
                sum -= books[pointer1];
                maxPtD = max(maxPtD, pointer2 - pointer1 + 1);
                pointer1++;
            }

            else {
                sum += books[pointer2];
                maxPtD = max(maxPtD, pointer2 - pointer1 + 1);
                if (pointer2 < n) pointer2++;
            }

        }

        printf("%d", maxPtD-1);

    }

    return 0;
}
