// UVa 10954 - Add All

#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

// template <typename T, typename Compare>
// void printPriorityQueue(const std::priority_queue<T, std::vector<T>, Compare>& pq) {
//     std::priority_queue<T, std::vector<T>, Compare> pqCopy = pq; // Create a copy of the priority queue

//     // Print the elements in the priority queue
//     while (!pqCopy.empty()) {
//         std::cout << pqCopy.top() << " ";
//         pqCopy.pop();
//     }
//     std::cout << std::endl;
// }

int main () {

    struct Compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    priority_queue<int, vector<int>, Compare> pq;
    int n, read;
    int first, second;
    
    while (true) {

        scanf("%d", &n);
        if (n == 0) break;

        while (pq.size() != 0) pq.pop();

        for (int i=1; i<=n; i++) {
            scanf("%d", &read);
            pq.push(read);
        }

        int cost = 0;

        while (pq.size() > 1) {
            
            // printPriorityQueue(pq);
            
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            
            pq.push(first + second);
            cost += first + second;
        }

        printf("%d\n", cost);
    }

    return 0;

}