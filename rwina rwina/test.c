#include <stdio.h>
#include <stdbool.h>

bool function(int *other) {
    int x;

    if (!other) {
        return function(&x);
    } else {
        return &x > other;
    }
}

int main() {

    printf("%s\n", function(NULL) ? "UP" : "Down");

    return 0;
}