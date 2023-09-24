#include <bits/stdc++.h>

using namespace std;

long long minimumPossibleSum(int n, int target) {

    long long ans = 0;
    vector<long long> arr;
    set<long long> possible;
    set<long long>::iterator it;
    long long firstElement, lastElement, tg;
    
    arr.push_back(1);

    for (int i=2; i<target-1; i++) possible.insert(i);

    while (!possible.empty() && arr.size() != n) {

            // for (int ja: possible) printf("ja %d\n", ja);
            // printf("qdsqsdqsdqd\n");
            it = possible.begin();
            firstElement = *it;
            arr.push_back(firstElement);
            possible.erase(firstElement);
            if (possible.count(target - firstElement) == 1)
                possible.erase(target - firstElement);

        }

    bool flag = 0;
    while (arr.size() != n) {

        lastElement = arr[arr.size() - 1];
        
        if (!flag) {
        if (lastElement == target)
            tg = target + 1;
        else
            tg = target;

            flag = 1;
        }
        
        arr.push_back(tg);
        tg++;

    }

    for (int i=0; i<n; i++) {
        ans += arr[i];
        // printf("arr[%d] = %d\n", i, arr[i]);
    }
    return ans;

}

int main() {

    printf("%lld", minimumPossibleSum(39636, 49035));

    return 0;
}