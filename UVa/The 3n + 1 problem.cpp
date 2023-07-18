// UVa 00100 - The 3n + 1 problem

// #include <cstdio>
// #include <unordered_set>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {

//     unordered_set<int> alreadySeen;
//     int i, j, n, max;
//     vector<int> maxes;

//     while (scanf("%d %d", &i, &j) == 2) {

//         printf("%d %d ", i, j);

//         if (i > j) {
//             int tmp = i;
//             i = j;
//             j = tmp;
//         }

//         maxes.clear();
//         for (int k=i; k <= j; k++) {
//             max = 1;
//             n = k;
            
//             if (alreadySeen.find(n) == alreadySeen.end()) {
//                 while (n - 1) {
                    
//                     if (alreadySeen.find(n) == alreadySeen.end()) {
//                         alreadySeen.insert(n);
//                     }

//                     max++;
//                     if (n%2) n = 3*n + 1;
//                     else n /= 2;
//                 }
//             }
            
//             else continue;

//             maxes.push_back(max);
//         }

//         max = *max_element(maxes.begin(), maxes.end());
//         printf("%d\n", max);
    
//     }

//     return 0;
// }


#include <cstdio>

int main() {

    int i, j, n, count, max;
    
    while (scanf("%d %d", &i, &j) != EOF) {

        printf("%d %d ", i, j);

        if (i > j) {
            int tmp = i;
            i = j;
            j = tmp;
        }

        max = 0;

        for (int k=i; k <=j; k++) {
            
            count = 1;
            n = k;
            
            while (n-1) {
                if (n%2) n = 3*n + 1;
                else n /= 2;
                count++;
            }

            if (count > max) max = count;
        }



        printf("%d\n", max);
    }

    return 0;
}