// UVa 11572 - Unique Snowflakes

#include <bits/stdc++.h>

using namespace std;


int longestUniqueSubarray(vector<int> arr){

    if (arr.size() == 1 || arr.size() == 0) return arr.size();

    int maxLength = 0;
    set<int> dict;

    int left = 0, right = 0;
    for(; right < arr.size(); right++){

        if (dict.count(arr[right]) == 0) dict.insert(arr[right]);
        else {
            maxLength = max(maxLength, right - left);

            while (left < right) {
                if (arr[left] != arr[right]) ;
                else {
                    left++;
                    break;
                }
                left++;
            }
        }

    }
    maxLength = max(maxLength, right - left);

    return maxLength;
}


int main() {

    int t, n, id, count, max;
    vector<int> vect;

    scanf("%d", &t);
    while(t--) {

        vect.clear();

        scanf("%d", &n);
        while (n--) {
            scanf("%d", &id);

            vect.push_back(id);
        }

        printf("%d\n", longestUniqueSubarray(vect));

    }

    return 0;
}