// UVa 481 - What Goes Up

#include <bits/stdc++.h>

using namespace std;

// this method is O(n^2)
// int main() {

//     vector<int> arr, lis, seq;
//     int num, n, max, maxIdx;

//     while (scanf("%d", &num) != EOF) {
//         arr.push_back(num);
//         lis.push_back(1);
//     }

//     n = arr.size();

//     for (int i=1; i<n; i++) {
//         for (int j=0; j<i; j++) {
//             if (arr[i] > arr[j] && lis[i] <= lis[j]) lis[i] = lis[j] + 1;
//         }
//     }

//     max = lis[0];
//     maxIdx = 0;
//     for(int i=0; i<n; i++) {
//         if (max <= lis[i]) {
//             max = lis[i];
//             maxIdx = i;
//         }
//     }

//     printf("%d\n-\n", max);

//     for(int i=maxIdx; i>=0; i--) {
//         if (lis[i] == max) {
//             seq.push_back(arr[i]);
//             max--;
//         }
//     }

//     for (int i=seq.size()-1; i>=0; i--) printf("%d\n", seq[i]);

//     return 0;
// }

void print(const vector<int> &seq,
           const vector<int> &path,
           int                pos)
{
    if (pos == -1)
        return;
    print(seq, path, path[pos]);
    cout << seq[pos] << endl;
}

int main()
{  
    int n;
    vector<int> seq;
    while (cin >> n)
        seq.push_back(n);

    // L[i] stores the smallest ending value of seq's length-i LIS.
    vector<int> L(seq.size());
    vector<int> L_id(seq.size());
    vector<int> path(seq.size());
    int lisEnd = 0, lisCount = 0;
    // O(nlogk) greedy + D&C algorithm (where k is the length of the LIS).
    for (int i = 0; i < seq.size(); ++i)
    {
        // Find the insert position of L.
        size_t pos = lower_bound(L.begin(), L.begin() + lisCount, seq[i]) 
                     - L.begin();
        L[pos] = seq[i];
        L_id[pos] = i;
        // Store seq[i]'s previous number.
        path[i] = pos? L_id[pos - 1] : -1;
        // If seq[i] was inserted to L's "end".
        if (pos == lisCount)
        {
            ++lisCount;
            lisEnd = i;
        }
    }
    
    cout << lisCount << "\n-\n";
    print(seq, path, lisEnd);

    return 0;
}