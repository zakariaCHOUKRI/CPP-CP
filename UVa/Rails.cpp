// UVa 00514 - Rails

#include <stack>
#include <cstdio>

using namespace std;

int main() {

    int numberOfCoaches, coach[1005];//, first=1;
    stack<int> s, arriving;

    while (true) {

        scanf("%d", &numberOfCoaches);
        if (numberOfCoaches == 0) break;
        // if (first != 1) printf("\n");
        // first = 0;

        while (true) {

            scanf("%d", &coach[0]);
            if (coach[0] == 0) break;

            for (int i=1; i<numberOfCoaches; i++) scanf("%d", &coach[i]);
            // for (int i=0; i<numberOfCoaches; i++) {
            //     printf("|%d|", coach[i]);
            // }printf("\n");

            while (!s.empty()) s.pop();

            while (!arriving.empty()) arriving.pop();
            for (int j=numberOfCoaches; j>=1; j--) arriving.push(j);
            // while (!arriving.empty()) {
            //     printf("|%d|", arriving.top());
            //     arriving.pop();
            // }printf("\n");
            // for (int j=numberOfCoaches; j>=1; j--) arriving.push(j);

            for (int k=0; k<numberOfCoaches; k++) {

                if (s.empty() && arriving.empty()) {
                    printf("Yes\n");
                    break;
                }

                if (s.empty() && !arriving.empty()) {
                    s.push(arriving.top());
                    arriving.pop();
                }


                if (coach[k] < s.top()) {
                    printf("No\n");
                    break;
                }

                while (coach[k] != s.top()) {
                    s.push(arriving.top());
                    arriving.pop();
                }
                s.pop();


            }
            
            if (s.empty() && arriving.empty()) {
                printf("Yes\n");
            }


        }
        printf("\n");
    }
    return 0;
}