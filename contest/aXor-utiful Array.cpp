#include <bits/stdc++.h>
#define sor3a ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


using namespace std;



int main() {

    sor3a

    // int t, n, a[100010], x, y, ans;
    // set<pair<int, int>> m;

    // // int jojOsTlatin = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;


    // for (int i=0; i<100010; i++) {
    //     for (int j=i; j<100010; j++) {
    //         x = i & j;
    //         y = i ^ j;
    //         if (x >= y) {
    //             m.insert(make_pair(i, j));
    //             m.insert(make_pair(j, i));
    //         }
    //     }
    // }

    // scanf("%d", &t);
    // while (t--) {

    //     scanf("%d", &n);
    //     for (int i=0; i<n; i++)
    //         scanf("%d", &a[i]);

    //     ans = 0;
    //     for (int i=0; i<n; i++) {
    //         for (int j=i+1; j<n; j++) {
    //             if (m.count(make_pair(a[i], a[j])))
    //                 ans++;
    //         }
    //     }

    //     printf("%d\n", ans);


    // }
// #define N 2

//     int arr[N] = {8, 12};
//     int ande[N][N], xore[N][N], both[N][N];
//     int x, y;

//     for (int i=0; i<N; i++) {
//         for (int j=i; j<N; j++) {
//             x = arr[i] & arr[j];
//             y = arr[i] ^ arr[j];
//             ande[i][j] = x;
//             ande[j][i] = x;
//             xore[i][j] = y;
//             xore[j][i] = y;
//         }
//     }

//     for (int i=0; i<N; i++) {
//         for (int j=i; j<N; j++) {
//             if (ande[i][j] >= xore[i][j]) {
//                 both[i][j] = 1;
//                 both[j][i] = 1;
//             }
//             else {
//                 both[i][j] = 0;
//                 both[j][i] = 0;
//             }
//         }
//     }

//     for (int i=0; i<N; i++)
//         printf("%d ", arr[i]);

//     printf("\n\n");

//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             printf("%d ", ande[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\n");

//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             printf("%d ", xore[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\n");

//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             printf("%d ", both[i][j]);
//         }
//         printf("\n");
//     }

    int t, n, a[100010], b[100010], x, y, ans, idx;
    bool breake;

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i]);

        breake = 0;
        for (int i=0; i<n; i++) {
            if (breake) break;
            b[i] = 0;
            idx = i;
            for (int j=i+1; j<n; j++) {
                x = a[i] & a[j];
                y = a[i] ^ a[j];
                if (x >= y)
                    b[i] += 1;
                if (b[i] == n-1) {
                    breake = 1;
                    break;
                }
            }
        }

        // for (int i=0; i<n; i++)
        //     printf("%d ", b[i]);
        // printf("\n");

        ans = 0;
        for (int i=0; i<idx+1; i++)
            ans = max(ans, b[i]);

        printf("%d\n", ans+1);

    }


}