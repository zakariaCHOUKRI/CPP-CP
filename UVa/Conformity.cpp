// UVa 11286 - Conformity

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, course, max;
    map<set<int>, int> dict;
    set<int> tempSet;

    while (true) {

        scanf("%d", &n);
        if (n == 0) break;

        dict.clear();
        while (n--) {

            tempSet.clear();
            for (int i=0; i<5; i++) {
                scanf("%d", &course);
                tempSet.insert(course);
            }

            if (dict.count(tempSet) == 1) dict[tempSet] += 1;
            else dict[tempSet] = 1;

        }

        max = 0;
        for (auto elem: dict) if (elem.second > max) max = elem.second;

        printf("%d\n", max);

    }

    return 0;
}