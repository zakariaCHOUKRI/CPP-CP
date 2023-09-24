// UVa 11995 - I Can Guess the Data Structure!

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, op, inp, choice, size;
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    bool accessStack, accessQueue, accessPQ;

    while (scanf("%d", &n) != EOF){

        choice = 30;
        size = 0;

        while(!st.empty()) st.pop();
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();

        accessQueue = true;
        accessStack = true;
        accessPQ = true;

        while(n--) {

            scanf("%d %d", &op, &inp);

            if(op == 2 && size == 0) {
                choice = 1;
                accessStack = false;
                accessQueue = false;
                accessPQ = false;
            }

            else if (op == 2 && size != 0){

                if (st.top() != inp && accessStack) {
                    choice /= 2;
                    accessStack = false;
                }
                if (q.front() != inp && accessQueue) {
                    choice /= 3;
                    accessQueue = false;
                }
                if (pq.top() != inp && accessPQ) {
                    choice /= 5;
                    accessPQ = false;
                }

                if (accessStack) st.pop();
                if (accessQueue) q.pop();
                if (accessPQ) pq.pop();

                size--;
            }
            
            else {
                st.push(inp);
                q.push(inp);
                pq.push(inp);
                size++;
            }

        }


        if (choice == 1) printf("impossible");
        else if (choice == 2) printf("stack");
        else if (choice == 3) printf("queue");
        else if (choice == 5) printf("priority queue");
        else printf("not sure");

        printf("\n");

    }

    return 0;
}