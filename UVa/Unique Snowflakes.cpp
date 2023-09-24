// UVa 11572 - Unique Snowflakes

#include <bits/stdc++.h>

using namespace std;

int longestUniqueSubArr(vector<int> arr) {

    // in this problem we use the window sliding technique

    map<int, int> seen; // store last position of occurence of given integer
    int maximum_length = 0;
    int start = 0;

    for(int end = 0; end < arr.size(); end++) {

        // check if element is already seen. If yes, put the index after it in the start variable
        // we choose the max between start and the index + 1, because sometimes a given integer
        // is seen but it was seen outside of the window so we can just keep start as it is
        if (seen.find(arr[end]) != seen.end()) start = max(start, seen[arr[end]] + 1);

        seen[arr[end]] = end;
        maximum_length = max(maximum_length, end - start + 1);
    }

    return maximum_length;
}

int main() {

    int t, n, id;
    vector<int> arr;

    scanf("%d", &t);
    while(t--) {

        arr.clear();

        scanf("%d", &n);
        while (n--) {
            scanf("%d", &id);
            arr.push_back(id);
        }

        printf("%d\n", longestUniqueSubArr(arr));
    }

    return 0;
}