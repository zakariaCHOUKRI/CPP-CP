// UVa 11136 - Hoax or what

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, amount;
    long long loss;
    multiset<int> bills;

    while (true) {

        scanf("%d", &n);
        if (n==0) break;

        bills.clear();
        loss = 0;

        while (n--) {

            scanf("%d", &k);
            while (k--) {
                scanf("%d", &amount);
                bills.insert(amount);
            }

            // printf("before pop (loss is %d): ", loss);
            // for(auto elem: bills) printf("%d ", elem);printf("\n");

            if (bills.size() >= 1) {
                multiset<int>::iterator first = bills.begin();
                multiset<int>::iterator last = --bills.end();
                loss += *last - *first;
                bills.erase(first);
                bills.erase(last);
            }

            // printf("after pop (loss is %d): ", loss);
            // for(auto elem: bills) printf("%d ", elem);printf("\n");

        }

        printf("%lld\n", loss);
    }


    return 0;
}